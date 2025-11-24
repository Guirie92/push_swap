/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:36 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/24 15:20:02 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	count;

	if (argc < 2)
	{
		ft_printf(STDERR_FILENO, CLR_RED "Error\n" CLR_RST);
		exit (EXIT_FAILURE);
	}
	count = parse_count_digits(argc, argv);
	ft_printf(STDOUT_FILENO, "count: %d\n", count);
	if (count == -1)
	{
		ft_printf(STDERR_FILENO, CLR_RED "Error\n" CLR_RST);
		exit (EXIT_FAILURE);
	}
	(void)count;

}
