/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:43 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/12 15:45:45 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parse(ac, av, &data))
		return (EXIT_FAILURE);
	if (create_mutex(&data) || create_threads(&data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
