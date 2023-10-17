/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:21:45 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/12 15:28:53 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	if (philo->last_eat_time + philo->data->time_to_die > get_time())
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
