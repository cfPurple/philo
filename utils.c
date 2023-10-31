#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	signe;
    int somme;
	int i;

	signe = 1;
	i = 0;
	somme = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		|| (str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
    while (str[i] >= '0' && str[i] <= '9')
	{
		somme = ((somme * 10) + (str[i] - '0'));
		i++;
	}
	return (somme * signe);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = '\0';
}

void print(t_philo *philo, char *str)
{
	if (philo->ph_data->game_over == 0)
	{
    	pthread_mutex_lock(&philo->ph_data->lock);
    	printf("%lld\t%d\t%s\n", timestamp(philo->ph_data), philo->id, str);
   		pthread_mutex_unlock(&philo->ph_data->lock);
	}

}