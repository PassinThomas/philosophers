/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:14:25 by tpassin           #+#    #+#             */
/*   Updated: 2024/07/26 18:34:48 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	print_msg(t_table *table, int key)
{
	pthread_mutex_lock(&table->print_mtx);
    
    if (key == DIED)
    {
       
    }
	else if (key == FORK)
		ft_putstr("has taken a fork", 2);
	else if (key == EAT)
        ft_putstr("is eating", 2);
	else if (key == THINK)
        ft_putstr("is thinking", 2);
	else if (key == SLEEP)
        ft_putstr("is sleeping", 2);
	pthread_mutex_unlock(&table->print_mtx);
}