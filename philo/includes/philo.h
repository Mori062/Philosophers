/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:20 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/10 02:18:14 by morishitash      ###   ########.fr       */
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
	int				time_to_die; // 最後の食べ始めた時間から死ぬまでの時間
	int				time_to_eat; // 食べる時間
	int				time_to_sleep; // 眠る時間
	int				num_of_must_eat; // ひとり何回食べるか 
	int				start_time; // プログラム開始時間
	pthread_mutex_t	*forks; // フォーク
	pthread_mutex_t	dead_mutex;
	bool			someone_dead;

}	t_philo_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_num;
	int				fork_right;
	int				fork_left;
	int				last_eat_time;
	bool			full;
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
void    think(t_philo *philo, t_philo_data *data);
void    take_fork(t_philo *philo, t_philo_data *data);
void    eating(t_philo *philo, t_philo_data *data);
void    sleep_philo(t_philo *philo, t_philo_data *data);

// philo_bool.c
bool	is_philo_dead(t_philo *philo);

// time.c
int	get_time(void);
void	on_your_mark(t_philo *philo);

// monitor.c
void	monitor(t_philo *philo);
#endif