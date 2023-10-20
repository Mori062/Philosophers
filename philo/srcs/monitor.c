#include "../includes/philo.h"

bool	is_dead_checker(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->someone_dead == true)
		return (pthread_mutex_unlock(&philo->data->dead_mutex), true);
	pthread_mutex_unlock(&philo->data->dead_mutex);
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].is_dead_mutex);
		if (philo[i].is_dead == true)
			return (pthread_mutex_unlock(&philo[i].is_dead_mutex), true);
		pthread_mutex_unlock(&philo[i].is_dead_mutex);
		if (get_time() - philo[i].last_eat_time > philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->is_dead_mutex);
			philo->is_dead = true;
			pthread_mutex_unlock(&philo->is_dead_mutex);
			pthread_mutex_lock(&philo->data->dead_mutex);
			philo->data->someone_dead = true;
			pthread_mutex_unlock(&philo->data->dead_mutex);
			printf("%d %d died\n", get_time() - philo->data->start_time, philo[i].id);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_full_checker(t_philo *philo)
{
	int	i;

	i = 0;
	// printf("%d\n", philo->data->num_of_philo);
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].full_mutex);
		if (philo[i].full == false)
		{
			// if (rand() % 10000000 == 0)
			// 	printf("--------------------------------------%dis not full\n", philo[i].id);
			pthread_mutex_unlock(&philo[i].full_mutex);
			return (false);
		}
		// if (rand() % 100000 == 0)
			// printf("--------------------------------------%dis full\n", philo[i].id);
		pthread_mutex_unlock(&philo[i].full_mutex);
		i++;
	}
	// printf("All philo ate %d times\n", philo->data->num_of_must_eat);
	return (true);
}

void	monitor(t_philo *philo)
{
	while (1)
	{
		if (is_dead_checker(philo) == true)
			break ;
		if (is_full_checker(philo) == true)
			break ;
	}
	// printf("monitor end\n");
}
