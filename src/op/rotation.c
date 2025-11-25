/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:21:45 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 16:56:59 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
 * Top moves to bottom
 * For example:
 * [0, 1, 2] -> [1, 2, 0]
 */
static void	rotate(t_stack *s)
{
	int	val;

	if (s->size < 2)
		return ;
	val = s->head;
	s->head = ft_mod(s->head + 1, s->cap);
	s->arr[get_idx(s, s->size - 1)] = val;
}

void	ra(t_stack *a)
{
	rotate(a);
	op_print("ra");
}

void	rb(t_stack *b)
{
	rotate(b);
	op_print("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	op_print("rr");
}
