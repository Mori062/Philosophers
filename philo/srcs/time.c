/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:16:30 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/19 03:10:28 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// milisecond
int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL); // need error handling
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	on_your_mark(t_philo *philo)
{
	while (1)
	{
		if (get_time() - philo->data->start_time > 1000)
			break ;
	}
}

void	ft_usleep(int time)
{
	int	end_time;

	end_time = get_time() + time;
	while (end_time > get_time())
	{
		usleep((end_time - get_time()) / 2 * 1000);
	}
}
