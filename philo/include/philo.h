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
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_each			*each;
}					t_data;

/* time */

long	delta_time(long	old);
long	get_time(void);
void	ft_sleep(long ms);

/* utils */

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

/* init */

int		parse(int ac, char **av, t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_data *data);

/* write */
void	take_fork(pthread_mutex_t *fork, pthread_mutex_t *write,
			int id, long time);
void	eat(pthread_mutex_t *write, int id, long time);
void	sleeping(pthread_mutex_t *write, int id, long time);
void	think(pthread_mutex_t *write, int id, long time);
void	died(pthread_mutex_t *write, int id, long time);

/* core */

int		philosophers(t_data *data);

#endif
