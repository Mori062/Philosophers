# include "../includes/philo.h"

void	print_arg_error(void)
{
    printf("Error: Invalid arguments\n");
    printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}
