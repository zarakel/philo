/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:47:40 by juan              #+#    #+#             */
/*   Updated: 2022/02/07 15:48:48 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "struct.h"

int		main(int ac, char **av);
t_philo	*init_struct(void);
void	error_san(int error, char *error_msg, int errorp);
int		catch_int(char **av, t_philo *philo);
int		dispatch(char **av, t_philo *philo, int error);
void	main_shit(t_philo *philo);
void	init_thread(t_philo *philo);
long	get_time(void);
void	*menu(void *arg);
void	miam_time(t_thread *thread);
void	sleep_time(t_thread *thread);
void	think_time(t_thread *thread);
int		check_nb_of_miam(t_philo *philo);
void	print_miam_timestamps(t_thread *thread);
void	ft_usleep(long time);
void	sky_time(t_philo *philo);
void	nihility(t_philo *philo);
void	death(t_philo *philo, int i);

#endif
