/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:24:55 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/04 17:04:54 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->dead_mtx, NULL))
		return (1);
	if (pthread_mutex_init(&table->count_meal_mtx, NULL))
	{
		pthread_mutex_destroy(&table->dead_mtx);
		return (1);
	}
	if (pthread_mutex_init(&table->last_meal_mtx, NULL))
	{
		pthread_mutex_destroy(&table->dead_mtx);
		pthread_mutex_destroy(&table->count_meal_mtx);
		return (1);
	}
	if (pthread_mutex_init(&table->print_mtx, NULL))
	{
		pthread_mutex_destroy(&table->dead_mtx);
		pthread_mutex_destroy(&table->count_meal_mtx);
		pthread_mutex_destroy(&table->last_meal_mtx);
		return (1);
	}
	return (0);
}

static void	init_forks(t_philo *philos, long i)
{
	if (philos->id % 2)
	{
		philos->l_fork = &philos->table->forks[i];
		philos->r_fork = &philos->table->forks[(i + 1)
			% philos->table->nb_philo];
	}
	else
	{
		philos->r_fork = &philos->table->forks[i];
		philos->l_fork = &philos->table->forks[(i + 1)
			% philos->table->nb_philo];
	}
}

int	init_philos(t_table *table)
{
	long	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philos)
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (1);
	memset(table->philos, 0, sizeof(t_philo) * table->nb_philo);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (1);
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].count_meal = 0;
		init_forks(&table->philos[i], i);
		i++;
	}
	if (init_mutex(table))
		return (1);
	return (0);
}

void	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
		pthread_mutex_destroy(&table->forks[i++]);
	free(table->philos);
	free(table->forks);
	pthread_mutex_destroy(&table->dead_mtx);
	pthread_mutex_destroy(&table->count_meal_mtx);
	pthread_mutex_destroy(&table->last_meal_mtx);
	pthread_mutex_destroy(&table->print_mtx);
	return ;
}
