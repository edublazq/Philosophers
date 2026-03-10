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
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>

struct	s_philo;

typedef struct s_table
{
	int				philos;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_each
{
	struct s_table	*table;
	struct s_philo	*main_struct;
	pthread_t		thread;
	int				id;
	int				n_foods;
	int				dead;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_each;

typedef struct s_philo
{
	int			n_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_times;
	pthread_t	monitor;
	pthread_t	write;
	t_table		table;
	t_each		*each;
}	t_philo;

/* INICIALIZATION */
int		save_info(t_philo *philo, char **av, int ac);
int		create_philo(t_each *each, int n_philos);

/* UTILS */
void	ft_sleep(int ms);
int		ft_atoi(const char *nptr);
void	ft_puterror(const char *s);
int		check_input(int ac, char **av);
void	*ft_calloc(size_t nmemb, size_t size);

/* DOOM EXIT */
int		doom_exit(t_philo *philo, int flag);

#endif
