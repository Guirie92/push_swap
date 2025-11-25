/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:21:45 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 15:16:31 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
/*
 * 1. Pops the value from SRC, and then
 * 2. Pushes it to DST
 */
void	push(t_stack *src, t_stack *dst)
{
	int	val;

	if (src->size == 0)
		return ;
	val = src->arr[src->head];
	src->head = ft_mod(src->head + 1, src->cap);
	src->size--;
	dst->head = ft_mod(dst->head - 1, dst->cap);
	dst->arr[dst->head] = val;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	op_print("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	op_print("pb");
}
