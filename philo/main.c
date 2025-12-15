/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:29:54 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/09 12:29:54 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (!check_input(ac, av))
	{
		ft_puterror("Usage: ./philo n_philos time_die time_eat time_sleep");
		ft_puterror("(Optional arg) n_times_must_eat");
		return (1);
	}
	if (!save_input(&philo, av, ac))
		return (ft_puterror("Malloc failed!"), 1);
	
	return (0);
}
