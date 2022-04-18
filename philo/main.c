#include "philo.h"

void	*ft_memset(void *buf, int c, size_t count)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char *)buf;
	i = 0;
	while (i < count)
	{
		*res = (unsigned char)c;
		res++;
		i++;
	}
	return (buf);
}

int	ft_count_num(const char *str)
{
	int	k;

	k = 0;
	while (*str)
	{
		if (*str > 47 && *str < 58)
			k++;
		str++;
	}
	return (k);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	char	sign;
	int		k;

	i = 0;
	res = 0;
	k = ft_count_num(str);
	sign = '+';
	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	if ((str[i] == 43 || str[i] == 45) && (ft_isdigit(str[i + 1])))
		sign = str[i++];
	while (str[i] > 47 && str[i] < 58)
		res = 10 * res + (int)(str[i++] - 48);
	if ((sign == '-') && (k > 18))
		return (0);
	else if ((sign == '-') && (k <= 18))
		return (res * (-1));
	else if ((k > 18) && (sign == '+'))
		return (-1);
	else
		return (res);
}

void	ft_init(int argc, char **argv, t_data data)
{
	data.input->number = ft_atoi(argv[1]);
	if (data.input->number > 200 || data.input->number < 1)
		ft_error("error: wrong number of philosophers!");
	data.input->die = ft_atoi(argv[2]);
	data.input->eat = ft_atoi(argv[3]);
	data.input->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.input->number_eat = ft_atoi(argv[5]);
}

void	*ft_phil(t_phils *data)
{
	printf("Hello\n");
	return (0);
}

void	ft_start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		pthread_create(&(data->trds_id[i]), NULL, ft_phil(), data);
		i++;
		pthread_join(&(data->trds_id[i]));
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 || argc !=6 )
		ft_error("error: wrong number of arguments!");
	else
	{
		ft_init(argc, argv, data);
		ft_start_threads(&data);
	}
	return (0);
}