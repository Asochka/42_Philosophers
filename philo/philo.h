#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

struct	s_data;

typedef struct	s_argv
{
	int	number; //number_of_philosophers
	int	die; //time_to_die
	int	eat; //time_to_eat
	int	sleep; //time_to_sleep
	int	number_eat; //[number_of_times_each_philosopher_must_eat]

	int	count;//???
} t_argv;

typedef struct s_phil
{
	int	id;
	int	right;//or t_mutex *min and t_mutex *max
	int	left;
	pthread_t	thr_id;
	int	num_of_times_ate;//num_of_times_ate
	long long	update_time;//time_to_die//time last meal
	struct s_data	*datas;

} t_phil;

typedef struct	s_data
{
	t_phil	phil[200];
	t_argv	input;
	pthread_mutex_t write;
	pthread_mutex_t forks[200];
	long	time0;
	bool	dead;
} t_data;

#endif