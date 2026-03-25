/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:46:15 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/12 15:46:15 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_input(int ac, char **av)
{
	size_t	i;
	size_t	j;

	if (ac != 6 && ac != 5)
		return (EXIT_FAILURE);
	i = 1;
	while ((i < 6 && ac == 6) || (i < 5 && ac == 5))
	{
		j = 0;
		if (!av[i])
			return (EXIT_FAILURE);
		while (j < ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parse(int ac, char **av, t_data *data)
{
	if (check_input(ac, av))
		return (EXIT_FAILURE);
	data->program_die = 0;
	data->n_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	if (data->n_philos <= 0 || data->time_to_die <= 0)
		return (EXIT_FAILURE);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (EXIT_FAILURE);
	if (ac == 6)
	{
		data->n_times = ft_atoi(av[5]);
		if (data->n_times <= 0)
			return (EXIT_FAILURE);
	}
	else
		data->n_times = -1;
	return (EXIT_SUCCESS);
}

int	init_forks(t_data *data)
{
	size_t	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->n_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->write, NULL);
	return (EXIT_SUCCESS);
}

int	init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	data->each = malloc(sizeof(t_each) * data->n_philos);
	if (!data->each)
		return (free(data->forks), EXIT_FAILURE);
	while (i < (size_t)data->n_philos)
	{
		pthread_mutex_init(&data->each[i].state, NULL);
		data->each[i].write = &data->write;
		data->each[i].main_struct = data;
		data->each[i].n_foods = 0;
		data->each[i].dead = 0;
		data->each[i].id = i + 1;
		data->each[i].im_the_one = 0;
		data->each[i].finished = 0;
		data->each[i].left = &data->forks[i];
		data->each[i].right = &data->forks[(i + 1) % data->n_philos];
		i++;
	}
	return (EXIT_SUCCESS);
}
