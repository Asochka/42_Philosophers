#include "philo.h"

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