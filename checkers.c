#include "philosophers.h"

int check_args(int ac, char **av)
{
    int nb;
    int i;

    i = 1;
    if (ac != 5 && ac != 6)
    {
        printf("\nInvalide number of arguments.\n");
        return (-1);
    }
    while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1 && nb > 200)
		{
			printf("max number of philo\n");
			return (-1);
		}
		if (nb <= 0)
		{
			printf("\nInvalide arguments.");
			return (-1);
		}
		i++;
	}
	return (0);
}

void checkers(t_param *data)
{
    int	i; //meal
	int	j; //death

	i = 0;
	j = 0;
	while (data->end == 0)
    {
        check_if_dead(&data->philo[j]);
        if (data->must_eat > 0)
        {
            i = 0;
            while (i < data->nb_philo)
			{
				if (data->philo[i].m_eaten < data->must_eat)
					break ;
			    i++;
			}
            if (i == data->nb_philo)
				data->end = 1;
        }
        if (j == data->nb_philo - 1)
		    j = -1;
        j++;
    }
}

void	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->ph_data->check);
	if ((timestamp(philo->ph_data) - philo->lastmeal) \
		>= philo->ph_data->time_to_die)
	{
		print(philo, "died");
		philo->ph_data->end = 1;
	}
	pthread_mutex_unlock(&philo->ph_data->check);
}
