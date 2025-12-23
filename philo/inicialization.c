/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:49:23 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/09 12:49:24 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int ac, char **av)
{
	int	i;
	int	value;

	i = 1;
	if (ac != 6 || ac != 5)
		return (0);
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		if (value <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	save_info(t_philo *philo, char **av, int ac)
{
	int	i;

	philo->n_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->n_times = ft_atoi(av[5]);
	else
		philo->n_times = -1;
	philo->philos = ft_calloc(sizeof(t_each), philo->n_philos);
	if (!philo->philos)
		return (0);
	philo->table.forks = ft_calloc(sizeof(pthread_mutex_t), philo->n_philos);
	if (!philo->table.forks)
		return (0);
	philo->table.philos = 0;
	i = 0;
	while (i < philo->n_philos)
		philo->philos[i++].dead = false;
	return (1);
}
