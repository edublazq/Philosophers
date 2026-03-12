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

int	check_input(int ac, char **av)
{
	
}

int	parse(int ac, char **av, t_data *data)
{
	if (check_input(ac, av))
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}
