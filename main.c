#include "philo.h"

void	ft_init(int argc, char **argv)
{
	
}

int	main(int argc, char **argv)
{
	if (argc != 5 || argc !=6 )
		write(1, "error: wrong number of arguments!", 33);
	else
	{
		ft_init(argc, argv);
	}
	return (0);
}