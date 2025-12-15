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

	i = 0;
	philo->n_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->n_times = ft_atoi(av[5]);
	else
		philo->n_times = -1;
	philo->threads = ft_calloc(sizeof(pthread_t), philo->n_philosophers);
	if (!philo->threads)
		return (0);
	philo->table.forks = ft_calloc(sizeof(bool), philo->n_philosophers);
	if (!philo->table.forks)
		return (0);
	philo->table.philos = 0;
	while (i < philo->n_philosophers)
		philo->table.forks[i++] = false;
	return (1);
}
