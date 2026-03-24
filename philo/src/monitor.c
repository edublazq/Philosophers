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

	i = 0;
	time = get_time();
	while (i < n_philos)
	{
		if (time >= data->each[i].last_meal)
		{
			data->program_die = 1;
			data->each[i].im_the_one = 1;
		}
		pthread_mutex_lock(&data->each[i].state);
			data->each[i].last_meal = time;
		pthread_mutex_unlock(&data->each[i].state);
		i++;
	}
}

void	*r_monitor(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	if (data->n_times >= 0)
	{
		while (i < data->n_times)
		{
			monitorize(data, data->n_philos);
			i++;
		}
		data->program_die = 1;
	}
	else
	{
		while (data->program_die == 0)
			monitorize(data, data->n_philos);
	}
	return (NULL);
}
