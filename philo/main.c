#include "philo.h"

// void	*ft_phil(t_data *data)
// {
// 	printf("Hello\n");
// 	return (0);
// }

int	ft_start_threads(t_data *data)
{
	// int	i;

	// i = 0;
	// while (i < data->number)
	// {
	// 	pthread_create(&(data->trds_id[i]), NULL, ft_phil(), data);
	// 	i++;
	// 	pthread_join(&(data->trds_id[i]));
	}
}

int	ft_init(int argc, char **argv, t_data *data)
{
	data->input.number = ft_atoi(argv[1]);
	if (data->input.number > 200 || data->input.number < 1)
		return (1);
	data->input.die = ft_atoi(argv[2]);
	data->input.eat = ft_atoi(argv[3]);
	data->input.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->input.number_eat = ft_atoi(argv[5]);
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
	{
		printf("error: invalid args!\n");
		return (1);
	}
	else
	{
		if (!(data = malloc(sizeof(t_data))))
			return (1);
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