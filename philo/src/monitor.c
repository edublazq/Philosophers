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
			monitorize(data->each);
		}
	}
	return (NULL);
}
