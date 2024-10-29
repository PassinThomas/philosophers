/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:11:06 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/29 16:26:41 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_table *table)
{
	int dead;

    dead = 0;
	pthread_mutex_lock(&table->dead_mtx);
	dead = table->dead;
	pthread_mutex_unlock(&table->dead_mtx);

	return (dead);
}