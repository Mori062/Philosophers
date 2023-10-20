/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:22:07 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/20 11:38:31 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo, t_philo_data *data)
{
	(void)data;
	pthread_mutex_lock(&philo->is_dead_mutex);
	if (philo->is_dead == true)
		return ;
	pthread_mutex_unlock(&philo->is_dead_mutex);
	pthread_mutex_lock(&philo->print_mutex);
	printf("%d %d is thinking\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
}

void	take_fork(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	if (philo->is_dead == true)
		return ;
	pthread_mutex_unlock(&philo->is_dead_mutex);
	pthread_mutex_lock(&data->forks[philo->fork_right]);
	if (philo->fork_right == philo->fork_left)
	{
		pthread_mutex_unlock(&data->forks[philo->fork_right]);
		pthread_mutex_lock(&philo->print_mutex);
		printf("%d %d is died\n", get_time() - data->start_time, philo->id);
		pthread_mutex_unlock(&philo->print_mutex);
		pthread_mutex_lock(&philo->is_dead_mutex);
		philo->is_dead = true;
		pthread_mutex_unlock(&philo->is_dead_mutex);
		return ;
	}
	pthread_mutex_lock(&data->forks[philo->fork_left]);
	pthread_mutex_lock(&philo->print_mutex);
	printf("%d %d has taken a fork\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
}

void	eating(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	if (philo->is_dead == true)
		return ;
	pthread_mutex_unlock(&philo->is_dead_mutex);
	pthread_mutex_lock(&philo->print_mutex);
	printf("%d %d is eating\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	philo->last_eat_time = get_time();
	philo->eat_num++;
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->fork_right]);
	pthread_mutex_unlock(&data->forks[philo->fork_left]);
	if (philo->eat_num == data->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->full_mutex);
		philo->full = true;
		pthread_mutex_unlock(&philo->full_mutex);
	}
}

void	sleep_philo(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	if (philo->is_dead == true)
		return ;
	pthread_mutex_unlock(&philo->is_dead_mutex);
	pthread_mutex_lock(&philo->print_mutex);
	printf("%d %d is sleeping\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	ft_usleep(data->time_to_sleep);
}
