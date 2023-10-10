#include "../includes/philo.h"
void	monitor(t_philo *philo)
{
	while (1)
	{
		
	}
	pthread_mutex_lock(&philo->data->dead_mutex);
	philo->data->someone_dead = true;
	pthread_mutex_unlock(&philo->data->dead_mutex);
}
