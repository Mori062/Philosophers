/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:43 by shmorish          #+#    #+#             */
/*   Updated: 2023/10/30 21:17:44 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*mutex_init(t_philo_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_of_philo);
	if (data->forks == NULL)
		return (free(data), NULL);
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	if (pthread_mutex_init(&data->is_dead_mutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&data->full_mutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&data->time_mutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&data->reference_mutex, NULL) != 0)
		return (NULL);
	return (data);
}

t_philo_data	*data_init(int argc, char **argv)
{
	t_philo_data	*data;

	(void)argc;
	data = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (data == NULL)
		return (NULL);
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->someone_dead = false;
	data->everyone_full = false;
	data->print_death = false;
	if (argv[5] != NULL)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = -1;
	if (mutex_init(data) == NULL)
		return (NULL);
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
		philo[i].fork_right = i;
		if (data->num_of_philo - i == 1)
			philo[i].fork_left = 0;
		else
			philo[i].fork_left = i + 1;
		philo[i].last_eat_time = get_time() + 1000;
		philo[i].is_dead = false;
		philo[i].full = false;
		philo[i].data = data;
		i++;
	}
	return (philo);
}
