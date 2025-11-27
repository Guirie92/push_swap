/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:02:22 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/27 21:46:51 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ps_algorithms.h"
# include "ps_ops.h"
# include "ps_solver.h"

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

/* parser */
long	parse_count_arr(t_ps_data *data, int argc, char **args, int i);
int		parse_args(t_ps_data *data, char **argv, int *tmp, int *dupcheck);
int		normalize_ranks(int *arr, size_t n);

/* utils */
void	op_print(const char *op);
int		get_idx(t_stack *s, int idx);
int		lookup(t_stack *s, int idx);
int		is_sorted(t_stack *s);

#endif /* PUSH_SWAP_H */