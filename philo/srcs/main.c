/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/08 18:13:16 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(t_philo *philo)
{
	on_your_mark(philo);
	if (philo->id % 2 == 0)
		sleep(1);
	while (1)
	{
		think();
		// printf("philo[%d] is thinking\n", philo->id);
		// if (is_philo_dead(philo) == DEAD)
		// 	break ;
		take_fork(philo, philo->data);
		eating(philo, philo->data);
		sleep_philo(philo->data);
	}

	return (NULL);
}

void	run_main(t_philo_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	printf("start_time: %d\n", data->start_time);
	data->start_time = get_time();
	printf(" data->num_of_philo: %d\n", data->num_of_philo);
	while (i < data->num_of_philo)
	{
		// create
		// printf("philo[%d] is created\n", philo[i].id);
		if (pthread_create(&philo[i].thread, NULL,
				(void *)routine, &philo[i]) != 0)
				exit(1);
		i++;
	}
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
	return (0);
}
