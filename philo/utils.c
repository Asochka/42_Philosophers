#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
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

void	ft_free_data(t_data *data, char *s)
{
	///////
	free(data);
	if (s)
		printf("%s\n", s);
}

int	ft_print_error(char *s)
{
	printf("%s\n", s);
	return (1);
}

long long	ft_timestamp(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

void	ft_print_output(t_data *data, char *str, t_phil *phil)
{
	if (!data->dead)
	{
		pthread_mutex_lock(&(data->write));
		printf("%lli ", timestamp() - data->time0);
		printf("%i ", phil->id + 1);
		printf("%s\n", str);
		pthread_mutex_unlock(&(data->write));
	}
}

void	ft_usleep(long long time)
{
	long long i;

	i = ft_timestamp();
	while (ft_timestamp() - i < time)
		usleep(time / 10);
}
// void	*ft_memset(void *buf, int c, size_t count)
// {
// 	size_t			i;
// 	unsigned char	*res;

// 	res = (unsigned char *)buf;
// 	i = 0;
// 	while (i < count)
// 	{
// 		*res = (unsigned char)c;
// 		res++;
// 		i++;
// 	}
// 	return (buf);
// }