#ifndef PHILO_H
# define PHILO_H
# include "struct.h"

int		main(int ac, char **av);
t_philo	*init_struct(void);
void	error_san(int error, char *error_msg);
void	catch_int(char **av, t_philo *philo);
void	main_shit(t_philo *philo);
void	init_thread(t_philo *philo);
long	get_time();
void	*menu();
void	miam_time(t_thread *thread);
void	sleep_time(t_thread *thread);
int	sky_time(t_thread *thread);
void	nihility(t_philo *philo);


#endif
