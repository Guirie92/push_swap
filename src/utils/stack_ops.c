/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 03:34:20 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 14:52:02 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	op_print(const char *op)
{
	ft_printf(STDOUT_FILENO, "%s\n", op);
}

int	get_idx(t_stack *s, int idx)
{
	int	val;

	val = ft_mod(s->head + idx, s->cap);
	return (val);
}

int	lookup(t_stack *s, int idx)
{
	return (s->arr[get_idx(s, idx)]);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (lookup(s, i) > lookup(s, i + 1))
			return (0);
		i++;
	}
	return (1);
}
