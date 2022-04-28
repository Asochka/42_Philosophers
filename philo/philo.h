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

# define MAX_NUM 200;

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
	int	right;
	int	left;
	pthread_t	thr_id;
	int	num_of_times_ate;
	long long	update_time;//time_to_die//time last meal
	struct s_data	*datas;

} t_phil;

typedef struct	s_data
{
	t_phil	phil[MAX_NUM];
	t_argv	input;
	pthread_mutex_t write;
	pthread_mutex_t forks[MAX_NUM];
	long long	time0;
	bool	dead;

	// int					dieded;
	// int					all_ate;
	// long long			first_timestamp;
	// pthread_mutex_t		meal_check;
} t_data;

#endif