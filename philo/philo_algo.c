#include "philo.h"

void	*ft_phil(t_data *data)//функция имитирующая работу философа
{
	// можно добавить задержку для четных философов! if i%2 == 0 (четный) usleep(2500)
	while (1)
	{
		//переменная dead == 1 то значит всех надо убить 
		//все принтф защитить мьютексом
		// lock(min_fork);
		// printf("philo X take a fork ");
		// lock(max_fork);
		// printf("philo X take a fork ");
		// printf("philo X eat ");
		// usleep(time_to_eat);
		// 		//обновить время последней еды
		// unlock();
		// unlock();

		// printf("philo X sleep ");
		// usleep(time_to_sleep);
		// printf("philo X think ");
	}
}

void	ft_philo_is_dead(t_data *data)
{
//получаем текущее время и смотрим на время последнего обеда фило получаем разницу и переводим в млсек и если оно больше чем time_to_die
//dead = 1 (чтобы всех потом убить)
	
}

int	ft_start_threads(t_data *data)
{
	int	i;
	t_phil	*phil;

	i = 0;
	data->time0 = ft_timestamp();
	phil = data->phil;
	while (i < data->input.number)
	{

		// game[i].filo = filo;
		// game[i].times_to_eat = 0;
		// if (pthread_create(&game[i].thread, NULL, gaming, (void *) &game[i]))
		// 	return (1);
		// game[i].update_time = get_current_time();
		if (pthread_create(&(phil[i].thr_id), NULL, ft_phil, (void *) &phil[i]))
			return (1);
		phil[i].update_time = timestamp();
		i++;
	}

	// 	check_if_alive(game->filo, game);
	// uninit(filo);
	// return (0);
}