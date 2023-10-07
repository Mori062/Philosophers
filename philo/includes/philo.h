/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:20 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/07 17:56:17 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo_data
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_must_eat;
	int		eat_count;
	int		start_time;
}	t_philo_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_num;
	int				fork_right;
	int				fork_left;
	int				last_eat_time;
	t_philo_data	*data;
}	t_philo;

typedef enum e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_status;

// print_error.c
void	print_arg_error(void);

// check_arg.c
bool    check_arg_value(int argc, char **argv);
bool	check_arg(int argc, char **argv);
int ft_atoi(const char *str);

// philo_init
t_philo_data	*data_init(int argc, char **argv);
t_philo	*philo_init(t_philo_data *data);

// action.c
void    think(void);
void    take_fork(void);
void    eating(void);
void    sleep_philo(void);

// philo_bool.c
t_status    is_philo_dead(t_philo *philo);

// time.c
int	get_time(void);
#endif