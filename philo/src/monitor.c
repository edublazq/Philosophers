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

void	monitorize(t_data *data, int n_philos)
{
	int		i;
	long	time;
	long	last_meal;

	i = 0;
	time = get_time();
	while (i < n_philos)
	{
		pthread_mutex_lock(&data->each[i].state);
		last_meal = data->each[i].last_meal;
		pthread_mutex_unlock(&data->each[i].state);
		if (time - last_meal >= data->time_to_die)
		{
			set_dead(data);
			pthread_mutex_lock(&data->each[i].state);
			data->each[i].im_the_one = 1;
			pthread_mutex_unlock(&data->each[i].state);
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
		sleep_no_check(1);
	}
	return (NULL);
}
