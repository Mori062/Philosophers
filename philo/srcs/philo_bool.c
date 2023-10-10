/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:21:45 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/10 00:52:51 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (false);
}
