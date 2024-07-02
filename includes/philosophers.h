/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:25:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/07/02 19:39:48 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
    int             nb_philo;
	int				eating;
	int				meals_eaten;
	long			last_meal;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	pthread_mutex_t	*write_lock;

}					t_philo;

typedef struct s_table
{
	int				is_dead;

}					t_table;

long				ft_atol(char *str);
int					check_char(char *str);
int					ft_parse(char **av, int ac, t_philo *p);

#endif