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
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table
{
	int				philos;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_each
{
	int		n_foods;	
	bool	dead;
}	t_each;

typedef struct s_philo
{
	int			n_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_times;
	pthread_t	master;
	t_table		table;
	t_each		*philos;
}	t_philo;

int		ft_atoi(const char *nptr);
void	ft_puterror(const char *s);
int		check_input(int ac, char **av);
int		save_info(t_philo *philo, char **av, int ac);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
