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

void	r_philo(t_data *data, t_each *philo, int id)
{
	while (!is_dead(data, philo))
	{
		think(philo);
		forks(data, philo, id);
		if (is_dead(data, philo))
			break ;
		eat(philo);
		remove_forks(data, philo, id);
		if (is_dead(data, philo))
			break ;
		sleeping(philo);
	}
}
void	*routine(void *args)
{
	t_each	*philo;
	t_data	*data;

	philo = (t_each *)args;
	data = philo->main_struct;
	if (philo->id % 2 == 0)
		ft_sleep(3, philo->main_struct, philo);
	r_philo(data, philo, philo->id);
	return (NULL);
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
	pthread_create(&data->monitor, NULL, r_monitor, data);
	i = 0;
	while (i < (size_t)data->n_philos)
	{
		pthread_join(each[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
	return (EXIT_SUCCESS);
}
