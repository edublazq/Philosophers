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
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>

struct	s_philo;

typedef struct s_each
{
	struct s_data	*main_struct;
	pthread_t		thread;
	int				id;
	int				finished;
	int				im_the_one;
	int				n_foods;
	int				dead;
	long			last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*write;
	pthread_mutex_t	state;
}					t_each;

typedef struct s_data
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times;
	int				program_die;
	long			time;
	pthread_t		monitor;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	pthread_mutex_t	*forks;
	t_each			*each;
}					t_data;

/* time */

long	delta_time(long old);
long	get_time(void);
void	sleep_no_check(long ms);
void	ft_sleep(long ms, t_data *data, t_each *each);

/* utils */

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		is_dead(t_data *data, t_each *each);
void	set_dead(t_data *data);
int		mid_fork_dead(pthread_mutex_t *fork);

/* init */

int		parse(int ac, char **av, t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_data *data);

/* write and actions */
int		forks(t_data *data, t_each *each, int id);
void	remove_forks(t_each *each, int id);
void	take_fork(pthread_mutex_t *fork, pthread_mutex_t *write,
			int id, long time);
void	eat(t_each *philo);
void	sleeping(t_each *philo);
void	think(t_each *philo);
void	died(t_each *philo);

/* core */

int		philosophers(t_data *data);
void	*r_monitor(void *args);
void	nukem(t_data *data);

#endif
