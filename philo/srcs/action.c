#include "../includes/philo.h"
void    think(void)
{
	printf("thinking\n");
}

void    take_fork(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&data->forks[philo->fork_right]);
	pthread_mutex_lock(&data->forks[philo->fork_left]);
	printf("take_fork\n");
}

void    eating(t_philo *philo, t_philo_data *data)
{
	philo->last_eat_time = get_time();
	philo->eat_num++;
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->forks[philo->fork_right]);
	pthread_mutex_unlock(&data->forks[philo->fork_left]);
	printf("eating\n");
}

void    sleep_philo(t_philo_data *data)
{
	printf("sleep_philo\n");
	usleep(data->time_to_sleep * 1000);
}
