#include "philo.h"

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
		data->phil[i].datas = data;
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
	data->dead = false;
	if (ft_init_mutex(data))
		return (1);
	return (0);
}