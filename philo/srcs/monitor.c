/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:23:04 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 02:03:40 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_dead_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		if (philo[i].is_dead == true)
			return (pthread_mutex_unlock(&philo->data->is_dead_mutex), true);
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		pthread_mutex_lock(&philo->data->time_mutex);
		// printf("pointer -> %p\n", &philo->data->time_mutex);
		if (get_time() - philo[i].last_eat_time > philo->data->time_to_die)
		{
			pthread_mutex_unlock(&philo->data->time_mutex);
			pthread_mutex_lock(&philo->data->is_dead_mutex);
			philo->is_dead = true;
			philo->data->someone_dead = true;
			pthread_mutex_unlock(&philo->data->is_dead_mutex);
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%d %d died\n", get_time() - philo->data->start_time,
				philo[i].id);
			pthread_mutex_unlock(&philo->data->print_mutex);
			return (true);
		}
		pthread_mutex_unlock(&philo->data->time_mutex);
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
		// if (rand() % 100000 == 0)
		// 	printf("-------------------\n");
		// printf("%d %d is not full\n", get_time() - philo->data->start_time, philo[i].id);
		pthread_mutex_lock(&philo->data->full_mutex);
		if (philo[i].full == false)
		{
			pthread_mutex_unlock(&philo->data->full_mutex);
			return (false);
		}
		pthread_mutex_unlock(&philo->data->full_mutex);
		i++;
	}
	pthread_mutex_lock(&philo->data->full_mutex);
	philo->data->everyone_full = true;
	pthread_mutex_unlock(&philo->data->full_mutex);
	return (true);
}

void	monitor(t_philo *philo)
{
	while (1)
	{
		if (is_dead_checker(philo) == true)
		{
			printf("dead monitor end\n");
			break ;
		}
		// if (rand() % 1000000 == 0)
		// 	printf("-------------------\n");
		if (is_full_checker(philo) == true)
		{
			printf("full monitor end\n");
			break ;
		}
	}
	printf("monitor end\n");
}
