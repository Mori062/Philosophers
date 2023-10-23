/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:22:07 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 10:53:48 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->is_dead == true || philo->data->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	print_thinking(philo, data);
}

void	take_fork(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->is_dead == true || philo->data->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	pthread_mutex_lock(&data->forks[philo->fork_right]);
	if (philo->fork_right == philo->fork_left)
	{
		pthread_mutex_unlock(&data->forks[philo->fork_right]);
		pthread_mutex_lock(&philo->data->print_mutex);
		if (philo->data->print_death == false)
			printf("%d %d is died\n", get_time() - data->start_time, philo->id);
		philo->data->print_death = true;
		pthread_mutex_unlock(&philo->data->print_mutex);
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		philo->is_dead = true;
		philo->data->someone_dead = true;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return ;
	}
	pthread_mutex_lock(&data->forks[philo->fork_left]);
	print_take_fork(philo, data);
}

void	eating(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->is_dead == true || philo->data->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	print_eating(philo, data);
	pthread_mutex_lock(&philo->data->time_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->data->time_mutex);
	philo->eat_num++;
	ft_msleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->fork_right]);
	pthread_mutex_unlock(&data->forks[philo->fork_left]);
	if (philo->eat_num == data->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->data->full_mutex);
		philo->full = true;
		pthread_mutex_unlock(&philo->data->full_mutex);
	}
}

void	sleep_philo(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->is_dead == true)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	print_sleeping(philo, data);
	ft_msleep(data->time_to_sleep);
}
