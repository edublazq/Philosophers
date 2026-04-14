/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:25:23 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/16 22:25:24 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	delta_time(long	old)
{
	long	delta;

	delta = get_time() - old;
	return (delta);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleep_no_check(long ms)
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(500);
}

void	ft_sleep(long ms, t_data *data)
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
	{
		if (is_dead(data))
			break ;
		usleep(500);
	}
}
