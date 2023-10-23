/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 02:13:13 by shmorish          #+#    #+#             */
/*   Updated: 2023/10/23 02:13:14 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	is_printable_action(t_philo *philo, t_philo_data *data)
{
	pthread_mutex_lock(&data->is_dead_mutex);
	if (philo->is_dead == true || data->someone_dead == true)
	{
		pthread_mutex_unlock(&data->is_dead_mutex);
		return (false);
	}
	pthread_mutex_unlock(&data->is_dead_mutex);
	return (true);
}

void	print_thinking(t_philo *philo, t_philo_data *data)
{
	if (is_printable_action(philo, data) == false)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d is thinking\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_take_fork(t_philo *philo, t_philo_data *data)
{
	if (is_printable_action(philo, data) == false)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d has taken a fork\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_eating(t_philo *philo, t_philo_data *data)
{
	if (is_printable_action(philo, data) == false)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d is eating\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_sleeping(t_philo *philo, t_philo_data *data)
{
	if (is_printable_action(philo, data) == false)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d is sleeping\n", get_time() - data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
