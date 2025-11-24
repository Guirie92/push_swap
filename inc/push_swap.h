/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:02:22 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 00:48:02 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // double-check
# include "ps_algorithms.h"

# define CLR_RED "\033[91m"
# define CLR_GRN "\033[38;2;58;204;140m"
# define CLR_RST "\033[0m"

typedef struct s_stack
{
	int		*arr;
	int		head;
	int		size;
	int		cap;
}	t_stack;

typedef struct s_ps_data
{
	long	count;
	long	result;
	int		argc;
	size_t	idx;
}	t_ps_data;

typedef enum e_retcode
{
	EMEM_FAIL = -1,
	E_ERROR,
	E_SUCESS,
}	t_retcode;

long	parse_count_digits(t_ps_data *data, int argc, char **args);
int		*parse_args(t_ps_data *data, char **argv, int *tmp, int *dupcheck);

#endif /* PUSH_SWAP_H */