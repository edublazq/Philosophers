/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:03:30 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/19 08:03:31 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_finish(t_data *data)
{
	int		i;
	int		end;
	t_each	*each;

	each = data->each;
	i = 0;
	end = 1;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&each[i].state);
		if (each[i].n_foods >= data->n_times)
			each[i].finished = 1;
		else
			end = 0;
		pthread_mutex_unlock(&each[i].state);
		i++;
	}
	if (end == 1)
		set_dead(data);
}

static void	monitorize(t_data *data, int n_philos)
{
	int		i;
	int		finished;
	long	last_meal;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_lock(&data->each[i].state);
		last_meal = data->each[i].last_meal;
		finished = data->each[i].finished;
		pthread_mutex_unlock(&data->each[i].state);
		if (finished)
		{
			i++;
			continue ;
		}
		if (get_time() - last_meal >= data->time_to_die)
		{
			set_dead(data);
			died(&data->each[i]);
			break ;
		}
		i++;
	}
}

void	*r_monitor(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (data->program_die == 0)
	{
		monitorize(data, data->n_philos);
		if (data->n_times > 0)
			check_finish(data);
		sleep_no_check(1);
	}
	return (NULL);
}
