#include "../includes/philo.h"

static bool    ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}


bool	check_arg(int argc, char **argv)
{
    int	i;
    int	j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (ft_isdigit(argv[i][j]) == false)
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool    check_arg_value(int argc, char **argv)
{
    int	i;

    i = 1;
    if (argv == NULL)
        return (false);
    while (i < argc)
    {
        if (ft_atoi(argv[i]) < 0)
            return (false);
        i++;
    }
    return (true);
}
