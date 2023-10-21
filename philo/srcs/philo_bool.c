/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:21:45 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/20 21:05:40 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->is_dead_mutex);
	pthread_mutex_lock(&philo->data->time_mutex);
	if (get_time() - philo->last_eat_time > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		philo->is_dead = true;
		philo->data->someone_dead = true;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
	}
	pthread_mutex_unlock(&philo->data->time_mutex);
	// pthread_mutex_unlock(&philo->data->is_dead_mutex);
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	return (false);
}
