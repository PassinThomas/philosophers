/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:25:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/11/01 19:09:39 by tpassin          ###   ########.fr       */
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

// Color
# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define G "\033[1;32m"   /* Bold Green */
# define Y "\033[1;33m"   /* Bold Yellow */
# define B "\033[1;34m"   /* Bold Blue */
# define M "\033[1;35m"   /* Bold Magenta */
# define C "\033[1;36m"   /* Bold Cyan */
# define W "\033[1;37m"   /* Bold White */

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

typedef struct s_philo
{
	pthread_t			thread;
	long				id;
	long				position;
	long				last_meal;
	t_mtx				mtx_count_meal;
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
	long				time_start_dinner;
	long				count_meal;
}						t_table;

int						ft_parse(char **av, int ac, t_table *p);
int						init_philos(t_table *table);
void					ft_clean(t_table *table);
void					print_status(t_philo *philo, int key);
long long				get_time(void);
void					ft_usleep(long long time);
void					eating(t_philo *philo);
void					sleeping(t_philo *philo);
void					thinking(t_philo *philo);
int						run_prog(t_table *table);
int						is_dead(t_table *table);
void					wait_time(long start_time);
void					set_death(t_table *table);

#endif