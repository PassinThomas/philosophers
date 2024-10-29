/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:46:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/10/29 15:35:36 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_atol(char *str)
{
	long	res;

	res = 0;
	while ((*str && *str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
		return (2147483650);
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res >= 2147483648)
			return (2147483650);
		str++;
	}
	return (res);
}

static int	check_char(char *str)
{
	if (!str || !*str)
		return (1);
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str != '+')
			break ;
		str++;
		break ;
	}
	while (ft_isdigit(*str))
		str++;
	if (*str == ' ' || *str == '\t')
	{
		while (*str == ' ' || *str == '\t')
			str++;
	}
	if (*str == '\0')
		return (0);
	else
		return (1);
}

int	ft_parse(char **av, int ac, t_table *p)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (ac == 5 || ac == 6)
	{
		while (av[++i])
		{
			nb = ft_atol(av[i]);
			if (check_char(av[i]) || nb == 2147483650)
				return (1);
		}
		p->nb_philo = ft_atol(av[1]);
		p->time_to_die = ft_atol(av[2]);
		p->time_to_eat = ft_atol(av[3]);
		p->time_to_sleep = ft_atol(av[4]);
		if (p->nb_philo <= 0 || p->nb_philo > 200 || p->time_to_die <= 0
			|| p->time_to_sleep <= 0 || p->time_to_eat <= 0)
			return (1);
		if (ac == 6)
			p->meal_nbr = ft_atol(av[5]);
		return (0);
	}
	return (1);
}
