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
	size_t	i;
	size_t	j;

	if (ac != 6 && ac != 5)
		return (EXIT_FAILURE);
	i = 1;
	while ((i < 6 && ac == 6) || (i < 5 && ac == 5))
	{
		j = 0;
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
	
	return (EXIT_SUCCESS);
}
