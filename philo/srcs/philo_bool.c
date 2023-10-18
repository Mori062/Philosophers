/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:21:45 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/18 22:04:38 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	if (get_time() - philo->last_eat_time > philo->data->time_to_die)
	{
		// printf("get_time() %d philo->last_eat_time %d diff %d < philo->data->time_to_die %d", get_time(), philo->last_eat_time,get_time() - philo->last_eat_time, philo->data->time_to_die);
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
