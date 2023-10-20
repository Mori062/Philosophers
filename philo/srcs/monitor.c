/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:23:04 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/20 12:39:46 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_dead_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].is_dead_mutex);
		if (philo[i].is_dead == true)
			return (pthread_mutex_unlock(&philo[i].is_dead_mutex), true);
		pthread_mutex_unlock(&philo[i].is_dead_mutex);
		if (get_time() - philo[i].last_eat_time > philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->is_dead_mutex);
			philo->is_dead = true;
			philo->data->someone_dead = true;
			pthread_mutex_unlock(&philo->is_dead_mutex);
			pthread_mutex_lock(&philo->print_mutex);
			printf("%d %d died\n", get_time() - philo->data->start_time,
				philo[i].id);
			pthread_mutex_unlock(&philo->print_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_full_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].full_mutex);
		if (philo[i].full == false)
		{
			pthread_mutex_unlock(&philo[i].full_mutex);
			return (false);
		}
		pthread_mutex_unlock(&philo[i].full_mutex);
		i++;
	}
	return (true);
}

void	monitor(t_philo *philo)
{
	while (1)
	{
		if (is_dead_checker(philo) == true)
			break ;
		if (is_full_checker(philo) == true)
			break ;
	}
}
