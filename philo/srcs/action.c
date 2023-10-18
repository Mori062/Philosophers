#include "../includes/philo.h"
void    think(t_philo *philo, t_philo_data *data)
{
	(void)data;
	printf("%d %d is thinking\n", get_time() - data->start_time, philo->id);
}

void    take_fork(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&data->forks[philo->fork_right]);
	if (philo->fork_right == philo->fork_left)
	{
		pthread_mutex_unlock(&data->forks[philo->fork_right]);
		printf("%d %d is died\n",get_time() - data->start_time, philo->id);
		exit(0);
	}
	pthread_mutex_lock(&data->forks[philo->fork_left]);
	printf("%d %d has taken a fork\n", get_time() - data->start_time, philo->id);
}

void    eating(t_philo *philo, t_philo_data *data)
{
	printf("%d %d is eating\n", get_time() - data->start_time, philo->id);
	philo->last_eat_time = get_time();
	philo->eat_num++;
	if (philo->eat_num == data->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->full_mutex);
		philo->full = true;
		pthread_mutex_unlock(&philo->full_mutex);
	}
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->fork_right]);
	pthread_mutex_unlock(&data->forks[philo->fork_left]);
}

void    sleep_philo(t_philo *philo, t_philo_data *data)
{
	printf("%d %d is sleeping\n", get_time() - data->start_time, philo->id);
	ft_usleep(data->time_to_sleep);
}
