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

void	even(t_data *data, t_each *philo)
{
	philo->time = get_time();
	philo->last_meal = get_time();
	while (1 && data->program_die == 0)
	{
		think(philo->write, philo->id, philo->time);
		if (philo->left < philo->right)
		{
			take_fork(philo->left, philo->write, philo->id, philo->time);
			take_fork(philo->right, philo->write, philo->id, philo->time);
		}
		else
		{
			take_fork(philo->right, philo->write, philo->id, philo->time);
			take_fork(philo->left, philo->write, philo->id, philo->time);
		}
		eat(philo->write, philo->id, philo->time);
		philo->n_foods++;
		ft_sleep(data->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		sleeping(philo->write, philo->id, philo->time);
		ft_sleep(data->time_to_sleep);
	}
}

void	odd(t_data *data, t_each *philo)
{
	philo->time = get_time();
	philo->last_meal = get_time();
	while (data->program_die == 0 && philo->finished == 0)
	{
		think(philo->write, philo->id, philo->time);
		if (philo->left < philo->right)
		{
			take_fork(philo->left, philo->write, philo->id, philo->time);
			take_fork(philo->right, philo->write, philo->id, philo->time);
		}
		else
		{
			take_fork(philo->right, philo->write, philo->id, philo->time);
			take_fork(philo->left, philo->write, philo->id, philo->time);
		}
		eat(philo->write, philo->id, philo->time);
		philo->n_foods++;
		ft_sleep(data->time_to_eat);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		sleeping(philo->write, philo->id, philo->time);
		ft_sleep(data->time_to_sleep);
	}
	if (philo->im_the_one)
		died(philo->write, philo->id, philo->time);
}

void	*routine(void *args)
{
	t_each	*philo;
	t_data	*data;

	philo = (t_each *)args;
	data = philo->main_struct;
	if (philo->id % 2 == 0)
	{
		even(data, philo);
		ft_sleep(3);
	}
	else
		odd(data, philo);
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
