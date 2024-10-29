/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:50:54 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/29 16:54:01 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->last_meal = philo->table->time_start_dinner;
	wait_time(philo->table->time_start_dinner);
	if (philo->id % 2)
		ft_usleep(philo->table->time_to_eat);
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
}

int	run_prog(t_table *table)
{
	int i;

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
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}