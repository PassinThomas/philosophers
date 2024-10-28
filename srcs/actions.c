/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:30:04 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/28 16:27:31 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_status(philo->table, FORK);
	pthread_mutex_lock(&philo->r_fork);
	print_status(philo->table, FORK);
	// check_end
	print_status(philo->table, EAT);
	pthread_mutex_lock(&philo->last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->mtx_count_meal);
	philo->table->count_meal++;
	pthread_mutex_unlock(&philo->mtx_count_meal);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	print_status(philo->table, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo->table, THINK);
	if (!philo->id % 2)
		return ;
	if (philo->table->time_to_sleep > philo->table->time_to_eat)
		return ;
	else
		ft_usleep(philo->table->time_to_eat);
}