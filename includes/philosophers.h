/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:25:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/06 13:36:18 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_t_msg
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIED,
}						t_msg;

typedef pthread_mutex_t	t_mtx;

typedef struct s_table	t_table;

typedef struct s_data_time
{
	size_t				start;
	size_t				now;
	size_t				remaining;
	size_t				sleep_time;
}						t_data_time;

typedef struct s_philo
{
	pthread_t			thread;
	long				id;
	long				position;
	long				last_meal;
	long				count_meal;
	t_mtx				*r_fork;
	t_mtx				*l_fork;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	t_philo				*philos;
	pthread_t			monitor;
	t_mtx				*forks;
	t_mtx				dead_mtx;
	t_mtx				count_meal_mtx;
	t_mtx				print_mtx;
	t_mtx				last_meal_mtx;
	t_mtx				death_lock;
	int					nb_philo;
	int					dead;
	long				time_to_eat;
	long				time_to_die;
	long				time_to_sleep;
	long				meal_nbr;
	size_t				time_start_dinner;
}						t_table;

int						ft_parse(char **av, int ac, t_table *p);
int						init_philos(t_table *table);
void					ft_clean(t_table *table);
void					print_status(t_philo *philo, int key);
size_t					get_time(void);
void					ft_usleep(size_t time, t_table *table);
void					eating(t_philo *philo);
void					sleeping(t_philo *philo);
void					thinking(t_philo *philo);
int						run_prog(t_table *table);
int						is_dead(t_table *table);
void					wait_time(size_t start_time);
#endif