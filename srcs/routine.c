/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:50:54 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/28 17:10:26 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine_philo(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	philo->last_meal = philo->table->time_start_dinner;
    wait_time(philo->table->time_start_dinner);
	if (philo->id % 2)
		ft_usleep(philo->table->time_to_eat);
    while (!end_simu)
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (args);
}

int run_prog()