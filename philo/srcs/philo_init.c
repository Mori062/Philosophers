# include "../includes/philo.h"

t_philo *philo_init(t_philo *philo, int argc, char **argv)
{
    int	i;

    i = 0;
    philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
    if (philo == NULL)
        return (NULL);
    while (i < ft_atoi(argv[1]))
    {
        philo[i].philo_num = i + 1;
        philo[i].philo_num = ft_atoi(argv[1]);
        philo[i].time_to_die = ft_atoi(argv[2]);
        philo[i].time_to_eat = ft_atoi(argv[3]);
        philo[i].time_to_sleep = ft_atoi(argv[4]);
        philo[i].eat_count = 0;
        philo[i].is_eating = false;
        philo[i].is_sleeping = false;
        philo[i].is_thinking = false;
        philo[i].is_dead = false;
        philo[i].is_full = false;
        philo[i].fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if (philo[i].fork == NULL)
            return (NULL);
        pthread_mutex_init(philo[i].fork, NULL);
        i++;
    }
    return (philo);
}