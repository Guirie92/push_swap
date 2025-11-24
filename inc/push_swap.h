/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:02:22 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/24 15:20:20 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // double-check

# define CLR_RED "\033[91m"
# define CLR_GRN "\033[38;2;58;204;140m"
# define CLR_RST "\033[0m"

typedef struct s_stack
{
	int		*arr;
	int		head;
	int		size;
	int		cap;
	char	id;
}	t_stack;

int	parse_count_digits(int argc, char **args);

#endif /* PUSH_SWAP_H */