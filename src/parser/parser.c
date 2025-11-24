/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:08:03 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 00:28:32 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
 * Accepts single arguments, arguments with quotation marks, multiple numbers
 * within an argument, or any combination of them. It invalidates everything
 * else, including things like "-" (sign without a number following it)
 */
long	parse_count_digits(t_ps_data *data, int argc, char **args)
{
	int		i;
	char	*arg;

	i = 1;
	data->count = 0;
	while (i < argc)
	{
		arg = args[i];
		while (*arg)
		{
			while (ft_isspace(*arg))
				arg++;
			if (*arg == '+' || *arg == '-')
				arg++;
			if (!ft_isdigit(*arg))
				return (-1);
			while (ft_isdigit(*arg))
				arg++;
			data->count++;
			if (!ft_isspace(*arg) && *arg)
				return (-1);
		}
		i++;
	}
	return (data->count);
}

long	ft_atol(t_ps_data *data, char **str, int *error)
{
	int		sign;

	data->result = 0;
	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		data->result = data->result * 10 + (**str - '0');
		if ((data->result * sign) > INT_MAX || (data->result * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		(*str)++;
	}
	while (ft_isspace(**str))
		(*str)++;
	return (data->result * sign);
}

int	process_arg(t_ps_data *data, char *str, int *tmp, int *dupcheck)
{
	long	val;
	int		error;

	error = 0;
	while (*str)
	{
		val = ft_atol(data, &str, &error);
		if (error)
			return (E_ERROR);
		tmp[data->idx] = (int)val;
		dupcheck[data->idx] = (int)val;
		data->idx++;
	}
	return (E_SUCESS);
}

int	*parse_args(t_ps_data *data, char **args, int *tmp, int *dupcheck)
{
	//int		error;
	int		i;

	//error = 0;
	i = 0;
	data->idx = 0;
	while (i < data->argc - 1)
	{
		if (process_arg(data, args[i + 1], tmp, dupcheck) == E_ERROR)
			return (NULL);
		i++;
	}

	/* JUST FOR DEBUGGING (BELOW), DELETE */
	for(int k = 0; k < data->count; k++)
	{
		ft_printf(STDOUT_FILENO, "%d - ", tmp[k]);
		ft_printf(STDOUT_FILENO, "%d\n", dupcheck[k]);
	}
	(void)dupcheck;
	return (NULL);
	/* JUST FOR DEBUGGING (ABOVE), DELETE */
}
