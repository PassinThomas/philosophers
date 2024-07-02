/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:46:50 by tpassin           #+#    #+#             */
/*   Updated: 2024/07/02 19:41:05 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *str)
{
	long	res;
	long	len;

	len = 0;
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
		str++;
		len++;
	}
	if (res >= 2147483648 || len > 10 || len == 0)
		return (2147483650);
	return (res);
}

int	check_char(char *str)
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

int	ft_parse(char **av, int ac, t_philo *p)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (ac != 5 && ac != 6)
		return (1);
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
	if (ac == 6)
		p->eating = ft_atol(av[5]);
	if (p->nb_philo <= 0 || p->nb_philo >= 200 || p->time_to_die <= 0
		|| p->time_to_sleep <= 0 || p->time_to_eat <= 0)
		return (1);
	return (0);
}
