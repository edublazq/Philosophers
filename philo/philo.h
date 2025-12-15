/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:30:18 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/09 12:30:18 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table
{
	int	philos;
	int	*forks;
}	t_table;

typedef struct s_philo
{
	int			n_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_times;
	pthread_t	*threads;
	pthread_t	master;
	t_table		table;
}	t_philo;

int		ft_atoi(const char *nptr);
void	ft_puterror(const char *s);
int		check_input(int ac, char **av);
void	save_info(t_philo *philo, char **av, int ac);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
