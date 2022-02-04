/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2022/02/04 16:55:01 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	error_san(int error, char *error_msg, int errorp)
{
	if (error == ERRNO0)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO1)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO3)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO4)
		write(2, error_msg, ft_strlen(error_msg));
	errorp = 1;
}

void	dam_use(t_thread *thread)
{
	if ((thread->number == 1 || thread->number == thread->access->number_of_philosophers)
			&& thread->access->number_of_philosophers % 2 == 1)
	{
		if (thread->dam == 1)
			thread->dam--;
		else
			thread->dam++;
	}
}

void	death(t_philo *philo, int i)
{
	usleep(1);
	philo->thread[i].local_time = get_time();
	printf("%ld ms	philo %d is dead\n", get_time()
		- philo->time, philo->thread[i].number);
	philo->dead = 1;
}
