/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:21:14 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/21 19:15:32 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_arg_error(void)
{
	ft_puterr("Error: Invalid arguments\n");
	ft_puterr("Usage: ./philo number_of_philosophers ");
	ft_puterr("time_to_die time_to_eat time_to_sleep ");
	ft_puterr("[number_of_times_each_philosopher_must_eat]\n");
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_puterr(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
