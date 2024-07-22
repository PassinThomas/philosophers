/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:24:55 by tpassin           #+#    #+#             */
/*   Updated: 2024/07/22 18:18:52 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->dead_mtx, NULL))
		return (1);
	if (pthread_mutex_init(&table->count_meal_mtx, NULL))
		return (1);
	if (pthread_mutex_init(&table->last_meal_mtx, NULL))
		return (1);
	if (pthread_mutex_init(&table->print_mtx, NULL))
		return (1);
	return (0);
}

int	init_philos(t_table *table)
{
	long i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->philos || !table->forks)
		return (1);
	memset(table->philos, 0, sizeof(t_philo) * table->nb_philo);
	while (i < table->nb_philo)
	{
        if (pthread_init_mutex(&table->forks[i], NULL))
            return (1);
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		i++;
	}
	return (0);
}

void ft_cleanning(t_table *table)
{
    free(table->philos);
    free(table->forks);
    return ;
}