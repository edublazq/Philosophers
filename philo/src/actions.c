/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:41:45 by edblazqu          #+#    #+#             */
/*   Updated: 2026/04/06 17:41:47 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks(t_data *data, t_each *each, int id)
{
	pthread_mutex_lock(&each->state);
	if (is_dead(data) || each->finished)
	{
		pthread_mutex_unlock(&each->state);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&each->state);
	if (id % 2 == 0)
	{
		take_fork(each->left, &data->write, each);
		if (is_dead(data))
			return (mid_fork_dead(each->left));
		take_fork(each->right, &data->write, each);
	}
	else
	{
		take_fork(each->right, &data->write, each);
		if (is_dead(data))
			return (mid_fork_dead(each->right));
		take_fork(each->left, &data->write, each);
	}
	return (EXIT_SUCCESS);
}

void	remove_forks(t_each *each, int id)
{
	if (id % 2 == 0)
	{
		pthread_mutex_unlock(each->right);
		pthread_mutex_unlock(each->left);
	}
	else
	{
		pthread_mutex_unlock(each->left);
		pthread_mutex_unlock(each->right);
	}
}
