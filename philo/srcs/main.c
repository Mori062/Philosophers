/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/07 17:15:31 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(t_philo *philo)
{
	// 同時に開始する
	if (philo->id % 2 == 1)
		sleep(1);
	while (1)
	{
		think();
		if (is_philo_dead(philo) == DEAD)
			break ;
		take_fork();
		eating();
		sleep_philo();
	}
}

void	run_main(t_philo_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	// get_time -> どっかに格納
	while (data->num_of_philo)
	{
		// create
		if (pthread_create(&philo[i].thread, NULL,
				(void *)routine, &philo[i]) != 0)
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
	data = data_init(data, argc, argv);
	if (data == NULL)
		return (1);
	philo = philo_init(data);
	if (philo == NULL)
		return (1);
	run_main(data, philo);
}
