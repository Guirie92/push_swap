/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:36 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/21 21:25:07 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	parse_count_digits(int argc, char **dgts)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		while (*(dgts[i]))
		{
			if (!ft_isdigit(*(dgts[i])) && *(dgts[i]) != ' '
				&& *(dgts[i]) != '-')
				return (-1);
			(dgts[i])++;
			count++;
		}
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	count;

	if (argc < 2)
	{
		ft_printf(STDERR_FILENO, "Error\n");
		exit (EXIT_FAILURE);
	}
	count = parse_count_digits(argc, argv);
}
