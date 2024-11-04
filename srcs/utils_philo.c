/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:14:25 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/04 16:25:27 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_time(long start_time)
{
	while (get_time() < start_time)
		continue ;
}

void	print_status(t_philo *philo, int key)
{
	pthread_mutex_lock(&philo->table->print_mtx);
	if (is_dead(philo->table) && key != DIED)
	{
		pthread_mutex_unlock(&philo->table->print_mtx);
		return ;
	}
	if (key == DIED)
		printf("%lld %ld is dead\n", get_time()
			- philo->table->time_start_dinner, philo->id);
	else if (key == FORK)
		printf("%lld %ld has taken a fork\n", get_time()
			- philo->table->time_start_dinner, philo->id);
	else if (key == EAT)
		printf("%lld %ld is eating\n", get_time()
			- philo->table->time_start_dinner, philo->id);
	else if (key == THINK)
		printf("%lld %ld is thinking\n", get_time()
			- philo->table->time_start_dinner, philo->id);
	else if (key == SLEEP)
		printf("%lld %ld is sleeping\n", get_time()
			- philo->table->time_start_dinner, philo->id);
	pthread_mutex_unlock(&philo->table->print_mtx);
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((long long)current_time.tv_sec * 1000 + current_time.tv_usec
		/ 1000);
}

void	ft_usleep(long long time, t_table *table)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + time;
	while (get_time() < end_time)
	{
		if (is_dead(table))
			break ;
		usleep(100);
	}
}
