#include "philosophers.h"

void    init_data(char **av, t_param *data)
{
    int i;
    i = 0;
    data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
		data->must_eat = ft_atoi(av[5]);
    else
        data->must_eat = 0;
    data->philo = malloc(data->nb_philo * (sizeof(t_philo)));//malloc des philo
    data->fork = malloc(data->nb_philo * (sizeof(pthread_mutex_t)));//malloc fork protegées
    while (i++ < data->nb_philo)
		pthread_mutex_init(&data->fork[i], NULL);//init mutex des fork
    init_philo(data);//init philo
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->check, NULL);
	data->end = 0;
	data->t0 = ft_time();
}

void    init_philo(t_param *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].l_fork = i;
		//printf("l_fork philo %d :%d\n", data->philo[i].id,data->philo[i].l_fork);
        data->philo[i].r_fork = (i + 1) % data->nb_philo;
		//printf("r_fork philo %d :%d\n", data->philo[i].id,data->philo[i].r_fork);
        data->philo[i].ph_data = data;
		data->philo[i].m_eaten = 0;
		data->philo[i].lastmeal = 0;
		i++;
	}
}