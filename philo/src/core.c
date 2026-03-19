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
	long	time;
	long	meal_time;

	time = get_time();
	meal_time = get_time();
	while (1 && data->program_die == 0)
	{
		think(philo->write, philo->id, &time);
		if (philo->left < philo->right)
		{
			take_fork(philo->left, philo->write, philo->id, &time);
			take_fork(philo->right, philo->write, philo->id, &time);
		}
		else
		{
			take_fork(philo->right, philo->write, philo->id, &time);
			take_fork(philo->left, philo->write, philo->id, &time);
		}
		eat(philo->write, philo->id, &time);
		ft_sleep(data->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		sleeping(philo->write, philo->id, &time);
		ft_sleep(data->time_to_sleep);
	}
}

void	odd(t_data *data, t_each *philo)
{
	long	time;
	long	meal_time;

	time = get_time();
	meal_time = get_time();
	while (1 && data->program_die == 0)
	{
		think(philo->write, philo->id, &time);
		if (philo->left < philo->right)
		{
			take_fork(philo->left, philo->write, philo->id, &time);
			take_fork(philo->right, philo->write, philo->id, &time);
		}
		else
		{
			take_fork(philo->right, philo->write, philo->id, &time);
			take_fork(philo->left, philo->write, philo->id, &time);
		}
		eat(philo->write, philo->id, &time);
		ft_sleep(data->time_to_eat);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		sleeping(philo->write, philo->id, &time);
		ft_sleep(data->time_to_sleep);
	}
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
	i = 0;
	while (i < (size_t)data->n_philos)
	{
		pthread_join(each[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
