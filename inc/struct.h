/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:26 by juan              #+#    #+#             */
/*   Updated: 2022/02/10 15:20:12 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>
# include <sys/time.h>

typedef struct s_thread	t_thread;
typedef struct s_philo	t_philo;

struct	s_philo
{
	int				error;
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			time_to_think;
	long			time;
	int				dead;
	int				eat_count;
	pthread_mutex_t	print;
	pthread_mutex_t	napkin;
	pthread_mutex_t	*fork;
	pthread_mutex_t	**next_fork;
	t_thread		*thread;
};

struct		s_thread
{
	pthread_t		thread;
	long			miamed;
	long			local_time;
	int				alive;
	int				number;
	int				famished;
	int				sleepy;
	t_philo			*access;
};

#endif
