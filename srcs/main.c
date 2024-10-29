/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:22:19 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/29 16:27:43 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;
	long	start_time;

	memset(&table, 0, sizeof(t_table));
	if (ft_parse(av, ac, &table))
		return (printf("Invalid Args\n"), 1);
	if (table.nb_philo == 1)
	{
		start_time = get_time();
		ft_usleep(table.time_to_die);
		return (printf("%lld philo is dead\n", get_time() - start_time), 1);
	}
	if (init_philos(&table))
		return (ft_clean(&table), 1);
	if (run_prog(&table))
		return (ft_clean(&table), 1);
	ft_clean(&table);
	return (0);
}
