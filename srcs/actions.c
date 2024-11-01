/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:30:04 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/01 19:14:02 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, FORK);
	if (is_dead(philo->table))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->table->last_meal_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->table->last_meal_mtx);
	ft_usleep(philo->table->time_to_eat);
	// pthread_mutex_lock(&philo->mtx_count_meal);
	// philo->table->count_meal++;
	// pthread_mutex_unlock(&philo->mtx_count_meal);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	if (is_dead(philo->table))
		return ;
	print_status(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (is_dead(philo->table))
		return ;
	print_status(philo, THINK);
	if (philo->table->nb_philo % 2 == 0)
		return ;
	if (philo->table->time_to_sleep > philo->table->time_to_eat)
		return ;
	else
		ft_usleep(philo->table->time_to_eat);
}