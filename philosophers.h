#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_param	t_param;
typedef struct s_philo		t_philo;

typedef struct s_param
{
    int     nb_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     must_eat;
    int     end;
    long long    t0;
    pthread_mutex_t	lock;
    t_philo *philo;
    pthread_mutex_t	*fork;
    pthread_mutex_t	check;

}               t_param;

typedef struct s_philo
{
    int id;
    pthread_t thread_id;
    int l_fork;
    int r_fork;
    int m_eaten;
    long long lastmeal;
    t_param *ph_data;
}               t_philo;


int     check_args(int ac, char **av);
int	    ft_atoi(char *str);
void    init_data(char **av, t_param *data);
void    init_philo(t_param *data);
void	philosopher(t_param *data);
void    *philo_rt(void *philo);
void    think(t_philo *philo);
void    eat(t_philo *philo);
void    philo_sleep(t_philo *philo);
long long	ft_time(void);
void   ft_usleep(int ms);
long long   timestamp(t_param *data);
void	end(t_param *data);
void    check_if_dead(t_philo *philo);
void    checkers(t_param *data);
void	*solo_philo(t_philo *philo);
void    print(t_philo *philo, char *str);

#endif
