#include "../includes/philo.h"

bool	is_dead_checker(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].is_dead_mutex);
		if (philo[i].is_dead == true)
		{
			pthread_mutex_unlock(&philo[i].is_dead_mutex);
			return (true);
		}
		pthread_mutex_unlock(&philo[i].is_dead_mutex);
		i++;
	}
	return (false);
}

bool	is_full_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].full_mutex);
		if (philo[i].full == false)
		{
			pthread_mutex_unlock(&philo[i].full_mutex);
			return (false);
		}
		pthread_mutex_unlock(&philo[i].full_mutex);
		i++;
	}
	return (true);
}

void	monitor(t_philo *philo)
{
	while (1)
	{
		if (is_dead_checker(philo) == true)
			break ;
		if (is_full_checker(philo) == true)
		{
			pthread_mutex_lock(&philo->data->dead_mutex);
			philo->data->someone_dead = true;
			pthread_mutex_unlock(&philo->data->dead_mutex);
			break ;
		}
	}
}
