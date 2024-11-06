/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:50:54 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/06 13:49:06 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->table->last_meal_mtx);
	time = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->table->last_meal_mtx);
	if (time >= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->dead_mtx);
		philo->table->dead = 1;
		pthread_mutex_unlock(&philo->table->dead_mtx);
		usleep(1000);
		print_status(philo, DIED);
		return (1);
	}
	return (0);
}

int	check_life(t_table *table)
{
	long	i;
	long	meal;

	i = 0;
	meal = 0;
	while (i < table->nb_philo)
	{
		if (check_death(&table->philos[i]))
			return (1);
		// if (table->meal_nbr)
		// {
		// 	pthread_mutex_lock(&table->count_meal_mtx);
		// 	if (table->philos[i].count_meal == table->meal_nbr)
		// 		meal++;
		// 	pthread_mutex_unlock(&table->count_meal_mtx);
		// 	if (meal == table->nb_philo)
		// 	{
		// 		pthread_mutex_lock(&table->dead_mtx);
		// 		table->dead = 1;
		// 		pthread_mutex_unlock(&table->dead_mtx);
		// 		return (1);
		// 	}
		// }
		i++;
	}
	return (0);
}

void	*routine_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->table->last_meal_mtx);
	philo->last_meal = philo->table->time_start_dinner;
	pthread_mutex_unlock(&philo->table->last_meal_mtx);
	wait_time(philo->table->time_start_dinner);
	if (philo->id % 2)
		ft_usleep(philo->table->time_to_eat, philo->table);
	while (!is_dead(philo->table))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (args);
}

void	*death_monitor(void *args)
{
	t_table	*table;

	table = (t_table *)args;
	wait_time(table->time_start_dinner);
	while (!is_dead(table))
	{
		if (check_life(table))
			break ;
		usleep(1000);
	}
	return (args);
}

int	run_prog(t_table *table)
{
	int	i;

	i = 0;
	table->time_start_dinner = get_time() + (table->nb_philo * 20);
	while (i < table->nb_philo)
	{
		table->philos[i].last_meal = table->time_start_dinner;
		if (pthread_create(&table->philos[i].thread, NULL, &routine_philo,
				&table->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&table->monitor, NULL, &death_monitor, table))
		return (1);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (1);
		i++;
	}
	if (pthread_join(table->monitor, NULL))
		return (1);
	return (0);
}
