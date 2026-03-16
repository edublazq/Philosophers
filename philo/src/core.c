/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:05 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/16 11:53:07 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_each	*philo;
	t_data	*data;

	philo = (t_each *)args;
	data = philo->main_struct;
	
}

int	philosophers(t_data *data)
{
	t_each	*each;
	size_t	i;

	i = 0;
	each = data->each;
	while (i < (size_t)data->n_philos)
	{
		pthread_create(&each[i].thread, NULL, routine, &each[i]);
		i++;
	}
	i = 0;
	while (i < (size_t)data->n_philos)
	{
		pthread_join(each[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
