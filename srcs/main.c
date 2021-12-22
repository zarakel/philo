/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:43 by juan              #+#    #+#             */
/*   Updated: 2021/12/22 02:26:54 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/struct.h"
#include "../inc/macro.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

t_philo	*init_struct(void)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->number_of_philosophers = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->time_to_think = 0;
	philo->time_to_die = 0;
	philo->number_of_times_each_philosopher_must_eat = 0;
	philo->famished = 1;
	philo->time = 0;
	return (philo);
}

void	init_thread(t_philo *philo)
{
	int	i;

	i = 1;
	philo->thread = malloc(sizeof(t_thread) * philo->number_of_philosophers);
	while (i <= philo->number_of_philosophers)
	{
		if (!philo->thread)
			error_san(ERRNO4, ERRMSG4);
		philo->thread[i].miamed = 0;
		philo->thread[i].alive = 1;
		philo->thread[i].number = i;
		philo->thread[i].local_time = 0; 
		pthread_mutex_init(&philo->thread[i].fork, NULL);
		if (i == philo->number_of_philosophers)
			philo->thread[i].next_fork = &philo->thread[1].fork;
		else
			philo->thread[i].next_fork = &philo->thread[i + 1].fork;
		philo->thread[i].access = philo;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	int		i;

	i = 1;
	philo = init_struct();
	if (ac == 5 || ac == 6)
	{
		catch_int(av, philo);
		init_thread(philo);
		main_shit(philo);
		while (sky_time(&philo->thread[i]) == 0 && philo->thread->alive == 1)
		{
			i++;
			if (i >= philo->number_of_philosophers)
				i = 1;
		}
		nihility(philo);
		return (0);
	}
	else 
		error_san(ERRNO0, ERRMSG0);
	return (0);
}
