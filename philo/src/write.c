/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:09:32 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/17 12:09:32 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(pthread_mutex_t *fork, pthread_mutex_t *write,
		int id, long time)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(write);
	printf("%ld %d has taken a fork\n", delta_time(time), id);
	pthread_mutex_unlock(write);
}

void	eat(t_each *philo)
{
	int	n_times;

	n_times = philo->main_struct->n_times;
	pthread_mutex_lock(&philo->state);
	philo->n_foods++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->state);
	pthread_mutex_lock(philo->write);
	printf("%ld %d is eating\n", delta_time(philo->main_struct->time), philo->id);
	pthread_mutex_unlock(philo->write);
	ft_sleep(philo->main_struct->time_to_eat, philo->main_struct);
}

void	sleeping(t_each *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%ld %d is sleeping\n", delta_time(philo->main_struct->time), philo->id);
	pthread_mutex_unlock(philo->write);
	ft_sleep(philo->main_struct->time_to_sleep, philo->main_struct);
}

void	died(t_each *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%ld %d died\n", delta_time(philo->main_struct->time), philo->id);
	pthread_mutex_unlock(philo->write);
}

void	think(t_each *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%ld %d is thinking\n", delta_time(philo->main_struct->time), philo->id);
	pthread_mutex_unlock(philo->write);
}
