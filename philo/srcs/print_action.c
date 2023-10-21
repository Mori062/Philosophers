#include "../includes/philo.h"

void	print_thinking(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d is thinking\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_take_fork(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d has taken a fork\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_eating(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d is eating\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_sleeping(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d is sleeping\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
