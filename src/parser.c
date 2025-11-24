/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:08:03 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/24 16:49:26 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse_count_digits(int argc, char **args)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		while (*(args[i]))
		{
			/* parse isspace */
			while (ft_isspace(*(args[i])))
				(args[i])++;

			/* parse sign */
			if (*(args[i]) == '+' || *(args[i]) == '-')
				(args[i])++;

			/* parse digits */
			while (ft_isdigit(*(args[i])))
				(args[i])++;
			count++;

			/* parse isspace */
			while (ft_isspace(*(args[i])))
				(args[i])++;

			/* invalidate */
			if (*(args[i]) && !(*(args[i]) == '+' || *(args[i]) == '-')
				&& !ft_isdigit(*(args[i])))
				return (-1);
		}
		i++;
	}
	return (count);
}
