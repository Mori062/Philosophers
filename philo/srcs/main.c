/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/19 02:04:16 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(t_philo *philo)
{
	on_your_mark(philo);
	philo->data->start_time = get_time();
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		// if (philo->id % 2 == 0)
		// 	printf("偶数！\n");
		think(philo, philo->data);
		if (is_philo_dead(philo) == true)
		{
			printf("%d %d died\n", get_time() - philo->data->start_time, philo->id);
			break ;
		}
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
	// printf("start_time: %d\n", data->start_time);
	data->start_time = get_time();
	// printf("data->num_of_philo: %d\n", data->num_of_philo);
	while (i < data->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)routine, &philo[i]) != 0)
		{
			printf("Error: pthread_create\n");
			exit(1);
		}
		i++;
	}
	monitor(philo);
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
