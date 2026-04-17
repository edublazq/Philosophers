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

void	one_philo(t_data *data)
{
	printf("0 1 is thinking\n");
	printf("0 1 has taken a fork\n");
	sleep_no_check(data->time_to_die);
	printf("%d 1 died\n", data->time_to_die);
}

void	r_philo(t_data *data, t_each *philo, int id)
{
	while (1)
	{
		pthread_mutex_lock(&philo->state);
		if (is_dead(data) || philo->finished)
		{
			pthread_mutex_unlock(&philo->state);
			break ;
		}
		pthread_mutex_unlock(&philo->state);
		think(philo);
		if (forks(data, philo, id))
			break ;
		if (is_dead(data))
		{
			remove_forks(philo, id);
			break ;
		}
		eat(philo);
		remove_forks(philo, id);
		if (is_dead(data))
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
	pthread_mutex_lock(&philo->state);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->state);
	if (philo->id % 2 == 0)
		sleep_no_check(1);
	r_philo(data, philo, philo->id);
	return (NULL);
}

int	philosophers(t_data *data)
{
	t_each	*each;
	int		i;

	i = 0;
	each = data->each;
	while (i < data->n_philos)
	{
		pthread_create(&each[i].thread, NULL, routine, &each[i]);
		i++;
	}
	pthread_create(&data->monitor, NULL, r_monitor, data);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(each[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
	return (EXIT_SUCCESS);
}
