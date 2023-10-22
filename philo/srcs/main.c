/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 02:02:38 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_everyone_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->full_mutex);
	if (philo->data->everyone_full == true)
	{
		pthread_mutex_unlock(&philo->data->full_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->full_mutex);
	return (false);
}

void	*routine(t_philo *philo)
{
	on_your_mark(philo);
	if (philo->id % 2 == 0)
		ft_msleep(10);
	while (1)
	{
		think(philo, philo->data);
		if (is_philo_dead(philo) == true)
		{
			printf("%d %d died\n", get_time() - philo->data->start_time, \
				philo->id);
			break ;
		}
		if (is_everyone_full(philo) == true)
			break ;
		take_fork(philo, philo->data);
		eating(philo, philo->data);
		sleep_philo(philo, philo->data);
	}
	return (NULL);
}

void	run_main(t_philo_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->start_time = get_time() + 1000;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, \
			(void *)routine, &philo[i]) != 0)
		{
			ft_puterr("Error: pthread_create\n");
			return ;
		}
		i++;
	}
	monitor(philo);
	i = 0;
	while (i < data->num_of_philo)
		pthread_join(philo[i++].thread, NULL);
	pthread_mutex_destroy(&data->is_dead_mutex);
	pthread_mutex_destroy(&data->full_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->time_mutex);
	pthread_mutex_destroy(&data->reference_mutex);
}

int	main(int argc, char **argv)
{
	t_philo_data	*data;
	t_philo			*philo;

	if (argc < 5 || argc > 6)
		return ((print_arg_error()), 1);
	if (check_arg(argc, argv) == false)
		return ((print_arg_error()), 1);
	if (check_arg_value(argc, argv) == false)
		return ((print_arg_error()), 1);
	data = data_init(argc, argv);
	if (data == NULL)
		return (1);
	philo = philo_init(data);
	if (philo == NULL)
		return (1);
	run_main(data, philo);
	free(data->forks);
	data->forks = NULL;
	free(data);
	data = NULL;
	free(philo);
	// system("leaks -q philo");
	return (0);
}
