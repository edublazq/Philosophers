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
		t_each *each)
{
	long	time;

	time = each->main_struct->time;
	pthread_mutex_lock(fork);
	pthread_mutex_lock(write);
	if (!is_dead(each->main_struct))
		printf("%ld %d has taken a fork\n", delta_time(time), each->id);
	pthread_mutex_unlock(write);
}

void	eat(t_each *philo)
{
	int		n_times;
	t_data	*data;

	data = philo->main_struct;
	n_times = philo->main_struct->n_times;
	pthread_mutex_lock(&philo->state);
	philo->n_foods++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->state);
	pthread_mutex_lock(philo->write);
	if (!is_dead(data))
		printf("%ld %d is eating\n", delta_time(data->time), philo->id);
	pthread_mutex_unlock(philo->write);
	ft_sleep(data->time_to_eat, data);
}

void	sleeping(t_each *philo)
{
	t_data	*data;

	data = philo->main_struct;
	pthread_mutex_lock(philo->write);
	if (!is_dead(data))
		printf("%ld %d is sleeping\n", delta_time(data->time), philo->id);
	pthread_mutex_unlock(philo->write);
	ft_sleep(data->time_to_sleep, data);
}

void	died(t_each *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%ld %d died\n", delta_time(philo->main_struct->time), philo->id);
	pthread_mutex_unlock(philo->write);
}

void	think(t_each *philo)
{
	t_data	*data;

	data = philo->main_struct;
	pthread_mutex_lock(philo->write);
	if (!is_dead(data))
		printf("%ld %d is thinking\n", delta_time(data->time), philo->id);
	pthread_mutex_unlock(philo->write);
}
