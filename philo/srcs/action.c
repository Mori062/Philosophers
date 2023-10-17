#include "../includes/philo.h"
void    think(t_philo *philo, t_philo_data *data)
{
	(void)data;
	printf("id: %d ", philo->id);
	printf("thinking\n");
}

void    take_fork(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&data->forks[philo->fork_right]);
	pthread_mutex_lock(&data->forks[philo->fork_left]);
	printf("id: %d ", philo->id);
	printf("take_fork\n");
}

void    eating(t_philo *philo, t_philo_data *data)
{
	philo->last_eat_time = get_time();
	philo->eat_num++;
	if (philo->eat_num == data->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->full_mutex);
		philo->full = true;
		pthread_mutex_unlock(&philo->full_mutex);
	}
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->forks[philo->fork_right]);
	pthread_mutex_unlock(&data->forks[philo->fork_left]);
	printf("id: %d ", philo->id);
	printf("eating\n");
}

void    sleep_philo(t_philo *philo, t_philo_data *data)
{
	printf("id: %d ", philo->id);
	printf("sleep_philo\n");
	usleep(data->time_to_sleep * 1000);
}
