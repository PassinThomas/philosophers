/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:14:25 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/22 17:07:04 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_table *table, int key)
{
	pthread_mutex_lock(&table->print_mtx);
	if (key == DIED)
	{
	}
	else if (key == FORK)
		printf("has taken a fork\n");
	else if (key == EAT)
		printf("is eating\n");
	else if (key == THINK)
		printf("is thinking\n");
	else if (key == SLEEP)
		printf("is sleeping\n");
	pthread_mutex_unlock(&table->print_mtx);
}

long int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((long int)current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
