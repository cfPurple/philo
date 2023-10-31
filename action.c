#include "philosophers.h"

void think(t_philo *philo)
{
    if (philo->ph_data->end == 0)
        print(philo, "is thinking");
}

void eat(t_philo *philo)
{
    if (philo->ph_data->end == 0)
    {
        pthread_mutex_lock(&philo->ph_data->fork[philo->l_fork]);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->ph_data->fork[philo->r_fork]);
        print(philo, "has taken a fork");
        print(philo, "is eating");
        philo->lastmeal = timestamp(philo->ph_data);
        philo->m_eaten += 1;
        ft_usleep(philo->ph_data->time_to_eat);
        pthread_mutex_unlock(&philo->ph_data->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->ph_data->fork[philo->r_fork]);
    }
}

void philo_sleep(t_philo *philo)
{
    if (philo->ph_data->end == 0)
    {
        print(philo, "is sleeping");
        ft_usleep(philo->ph_data->time_to_sleep);
    }
}

void   ft_usleep(int ms)
{
    long long t;
    t = ft_time();
    while(ft_time() - t < ms)
        usleep(ms / 10);
}

void	*solo_philo(t_philo *philo)
{

    //printf("solo philo\n");
    //printf("l_fork philo %d :%d\n", philo->id,philo->l_fork);
	pthread_mutex_lock(&philo->ph_data->fork[philo->l_fork]);
    //printf("has taken a fork\n");
	print(philo, "has taken a fork");
	ft_usleep(philo->ph_data->time_to_die);
	print(philo, "died");
	philo->ph_data->end = 1;
    return (NULL);
}