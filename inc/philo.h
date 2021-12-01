#ifndef PHILO_H
# define PHILO_H
# include "struct.h"

int		main(int ac, char **av);
void	init_struct(t_philo *philo);
void	error_san(int error, char *error_msg);
void	catch_int(char **av, t_philo *philo);

#endif
