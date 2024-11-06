/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:22:19 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/06 18:04:47 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (ft_parse(av, ac, &table) || (ac == 6 && table.meal_nbr < 1))
		return (printf("Invalid Args\n"), 1);
	if (init_philos(&table))
		return (ft_clean(&table), 1);
	if (run_prog(&table))
		return (ft_clean(&table), 1);
	ft_clean(&table);
	return (0);
}
