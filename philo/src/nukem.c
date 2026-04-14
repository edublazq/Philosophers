/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nukem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:33:57 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/23 10:33:58 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->dead);
	i = 0;
	while (i < data->n_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	i = 0;
	while (i < data->n_philos)
		pthread_mutex_destroy(&data->each[i++].state);
}

static void	kill_threads(t_each *each)
{
	t_data	*data;

	data = each->main_struct;
	free(data->forks);
	free(each);
}

void	nukem(t_data *data)
{
	destroy_mutex(data);
	kill_threads(data->each);
}
