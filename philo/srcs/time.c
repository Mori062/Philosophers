/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:16:30 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/21 18:40:28 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_puterr("gettimeofday error\n"));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	on_your_mark(t_philo *philo)
{
	int	time;

	time = philo->data->start_time - 1001;
	while (1)
	{
		if (get_time() - time > 1000)
			break ;
	}
}

void	ft_msleep(int time)
{
	int	end_time;

	end_time = get_time() + time;
	while (end_time > get_time())
	{
		usleep((end_time - get_time()) / 4 * 1000);
	}
}
