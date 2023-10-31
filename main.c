#include "philosophers.h"

//nombre de philo max???

int     main(int ac, char **av)
{
    t_param   *data;

    data = NULL;
    if (check_args(ac, av) != 0)
        return (-1);
    data = (t_param *)malloc(1 * sizeof(t_param));
    if (!data)
      return (-1);
    init_data(av, data);
    philosopher(data);
    end(data);
    return (0);
}