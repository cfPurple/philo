#include "philosophers.h"

void	philosopher(t_param *data)
{
	int		i;

	if (data->nb_philo == 1)
		solo_philo(data->philo);
	else
	{
		i = -1;
		while (++i < data->nb_philo)
			pthread_create(&data->philo[i].thread_id, NULL, &philo_rt, &data->philo[i]);
		while (data->end == 0)
			checkers(data);
	}
}

void    *philo_rt(void *philo)
{
	t_philo		*ph;

	ph = (t_philo *)philo;
    if (ph->id % 2 == 1)
            ft_usleep(ph->ph_data->time_to_eat);
	while(ph->ph_data->end == 0)
	{
		if(ph->ph_data->must_eat > 0 && ph->m_eaten == ph->ph_data->must_eat)
			break;
		eat(ph);
    	philo_sleep(ph);
    	think(ph);
	}
	return (NULL);
}

void	end(t_param *data)
{
	int	i;

	i = data->nb_philo - 1;
	while (i >= 0)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i--;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->check);
	printf("philo\n");
	free(data->philo);
	printf("fork\n");
	free(data->fork);
	printf("data\n");
	free(data);
}