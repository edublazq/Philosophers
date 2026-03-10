/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:04:38 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/10 13:04:39 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_philo *philo)
{
	size_t	i;
	t_each	*each;

	each = philo->each;
	i = 0;
	while (i < philo->n_philos)
		pthread_join(each[i++].thread, NULL);
	pthread_join(philo->monitor, NULL);
}

static void	destroy_mutex(t_philo *philo)
{
	size_t			i;
	pthread_mutex_t	*forks;

	pthread_mutex_destroy(&(philo->write));
	forks = philo->table.forks;
	i = 0;
	while (i < philo->n_philos)
		pthread_mutex_destroy(&forks[i++]);
}

static void	free_all(t_philo *philo)
{
	free(philo->each);
	free(philo->table.forks);
}

static void	print_error(t_error err)
{
	if (err == OK)
		return ;
	else if (err == MALLOC_ERR)
		ft_puterror("Philosophers: malloc error\n");
	else if (err == THREAD_ERR)
		ft_puterror("Philosophers: thread error\n");
	else if (err == MUTEX_ERR)
		ft_puterror("Philosophers: mutex error\n");
	else if (err == ARG_ERR)
		ft_puterror("Philosophers: arg error\n");
}

int	doom_exit(t_philo *philo, t_error flag)
{
	join_threads(philo);
	destroy_mutex(philo);
	free_all(philo);
	print_error(flag);
	return (flag);
}
