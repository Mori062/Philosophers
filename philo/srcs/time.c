/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:16:30 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/10 02:16:32 by morishitash      ###   ########.fr       */
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
	printf("on_your_mark [1] philo[%d] is created\n", philo->id);
	while (1)
	{
		if (get_time() - philo->data->start_time < 1000)
		{
			printf("------------------\n");
			printf("now: %d\n", get_time());
			printf("start_time: %d\n", philo->data->start_time);
			printf("philo[%d] is waiting\n", philo->id);
			usleep(100);
		}
		else
		{
			printf("philo[%d] start in %d\n", philo->id, get_time());
			break ;
		}
	}
	printf("on_your_mark [2] philo[%d] is created\n", philo->id);
}
