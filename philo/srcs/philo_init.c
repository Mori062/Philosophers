/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:43 by shmorish          #+#    #+#             */
/*   Updated: 2023/10/07 13:14:43 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo_data	*data_init(t_philo_data *philo, int argc, char **argv)
{
	int				i;
	t_philo_data	*data;

	i = 0;
	data = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (philo == NULL)
		return (NULL);
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->eat_count = ft_atoi(argv[5]);
	else
		data->eat_count = -1;
	return (data);
}

t_philo	*philo_init(t_philo_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (philo == NULL)
		return (free(data), NULL);
	while (i < data->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_num = 0;
		philo[i].data = data;
		philo[i].fork_right = i;
		philo[i].fork_left = i + 1;
		philo[i].last_eat_time = 0;
		i++;
	}
}
