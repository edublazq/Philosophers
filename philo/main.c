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
	if (!check_input(ac, av))
	{
		ft_puterror("Usage: ./philo n_philos time_die time_eat time_sleep times_eat");
	}
}
