#include "philo.h"

void	*ft_phil(t_data *data)//функция имитирующая работу философа
{
	// можно добавить задержку для четных философов! if i%2 == 0 (четный) usleep(2500)
	while (1)
	{
		//переменная dead == 1 то значит всех надо убить 
		//все принтф защитить мьютексом
		lock(min_fork);
		printf("philo X take a fork ");
		lock(max_fork);
		printf("philo X take a fork ");
		printf("philo X eat ");
		usleep(time_to_eat);
				//обновить время последней еды
		unlock();
		unlock();

		printf("philo X sleep ");
		usleep(time_to_sleep);
		printf("philo X think ");
	}
}

void	ft_philo_is_dead(t_data *data)
{
	//struct timeval last_time_eat для gettimeofday(struct timeval *, 0)
	//-long tv_sec
	//-long tv_usec
	// tv_sec * 1000 +tv_usec/1000 типо текущее время
//получаем текущее время и смотрим на время последнего обеда фило получаем разницу и переводим в млсек и если оно больше чем time_to_die
//dead = 1 (чтобы всех потом убить)
}

int	ft_start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number)
	{
		pthread_create(&(data->phil[i].id), NULL, ft_phil, data);
		i++;
		pthread_join(&(data->trds_id[i]));// в самом конце
	}
	// while (1)
	// {
	// 	while (ft_phil_is_dead(data) == 0)
	// освободить память и заджойнить потоки и дестрой мьютекс(?)
	// }
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input.number)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		data->phil[i].id = i;
		data->phil[i].right = (i + 1) % data->input.number;
		data->phil[i].left = i;
		data->phil[i].num_of_times_ate = 0;
		data->phil[i].update_time = 0;
	}
	if (pthread_mutex_init(&(data->write), NULL))
		return (1);
	rerurn (0);
}

int	ft_init(int argc, char **argv, t_data *data)
{
	data->input.number = ft_atoi(argv[1]);
	data->input.die = ft_atoi(argv[2]) * 1000;
	data->input.eat = ft_atoi(argv[3]) * 1000;
	data->input.sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->input.number_eat = ft_atoi(argv[5]);
	else
		(data->input.number_eat = -1);
	if (data->input.number > 200 || data->input.number < 1 || data->input.die < 0
			|| data->input.eat < 0 || data->input.sleep < 0 || ft_atoi(argv[5]) <= 0)
		return (1);
	if (ft_init_mutex(data))
		return (1);
	return (0);
}

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*argv[1] = '0')
		return (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 || argc !=6 || ft_check_argv(argv))
		return (ft_print_error("error: invalid args!"));
	else
	{
		if (!(data = malloc(sizeof(t_data))))
			return (ft_print_error("error: malloc"));
		if (ft_init(argc, argv, data))
		{
			ft_free_data(data, "error: initialization\n");
			return (1);
		}
		else if (ft_start_threads(data))
		{
			ft_free_data(data, "error: threads\n");
			return (1);
		}
	}
	ft_free_data(data, NULL);
	return (0);
}