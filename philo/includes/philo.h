/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:20 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 10:53:00 by morishitash      ###   ########.fr       */
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
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	full_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	reference_mutex;
	bool			someone_dead;
	bool			everyone_full;
	bool			print_death;
}	t_philo_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_num;
	int				fork_right;
	int				fork_left;
	int				last_eat_time;
	bool			is_dead;
	bool			full;
	t_philo_data	*data;
}	t_philo;

// print.c
void			print_arg_error(void);
int				ft_puterr(char *str);

// print_action.c
void			print_thinking(t_philo *philo, t_philo_data *data);
void			print_take_fork(t_philo *philo, t_philo_data *data);
void			print_eating(t_philo *philo, t_philo_data *data);
void			print_sleeping(t_philo *philo, t_philo_data *data);

// check_arg.c
bool			check_arg_value(int argc, char **argv);
bool			check_arg(int argc, char **argv);
int				ft_atoi(const char *str);

// philo_init
t_philo_data	*data_init(int argc, char **argv);
t_philo			*philo_init(t_philo_data *data);

// action.c
void			think(t_philo *philo, t_philo_data *data);
void			take_fork(t_philo *philo, t_philo_data *data);
void			eating(t_philo *philo, t_philo_data *data);
void			sleep_philo(t_philo *philo, t_philo_data *data);

// philo_bool.c
bool			is_philo_dead(t_philo *philo);

// time.c
int				get_time(void);
void			on_your_mark(t_philo *philo);
void			ft_msleep(int time);

// monitor.c
void			monitor(t_philo *philo);
bool			is_full_checker(t_philo *philo);
#endif