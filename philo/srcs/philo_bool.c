/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:21:45 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/19 03:01:45 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	// printf("get_time(): %d\n", get_time());
	// printf("last_eat_time: %d\n", philo->last_eat_time);
	// printf("get_time() - philo->last_eat_time: %d\n", get_time() - philo->last_eat_time);
	// printf("time_to_die: %d\n", philo->data->time_to_die);
	if (get_time() - philo->last_eat_time > philo->data->time_to_die)
	{
		philo->is_dead = true;
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->someone_dead = true;
		pthread_mutex_unlock(&philo->data->dead_mutex);
	}
	pthread_mutex_unlock(&philo->is_dead_mutex);
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (false);
}
