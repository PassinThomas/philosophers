/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:22:19 by tpassin           #+#    #+#             */
/*   Updated: 2024/07/22 16:24:19 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table = {0};
	if (ft_parse(av, ac, &table))
		return (printf("Invalid Args\n"), 1);
	if (init_philos(&table))
		return (1);
	
	//malloc nbr philo + protect malloc;
	return (0);
}
