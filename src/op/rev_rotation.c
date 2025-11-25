/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:21:45 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 16:57:04 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
 * Bottom moves to top
 * For example:
 * [0, 1, 2] -> [2, 0, 1]
 * I corrected a situation where we might have the following array
 * [-, 1, 2, 6, -] 
 * then, if we treat it as a circular array without two indices, we will always
 * start at index 0, not at index 1, as in this example, and using mod with
 * size rather than cap without knowing what the first index of the array is
 * will pose problems. therefore, we always subtract from the head, going
 * towards 0 index, and then bring the last element (size - 1) back at head's
 * position:
 * [6, 1, 2, -, -]
 */
static void	rev_rotate(t_stack *s)
{
	int	val;

	if (s->size <= 2)
		return ;
	val = s->arr[get_idx(s, s->size - 1)];
	s->head = ft_mod(s->head - 1, s->cap);
	s->arr[s->head] = val;
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	op_print("rra");
}

void	rrb(t_stack *b)
{
	rev_rotate(b);
	op_print("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	op_print("rrr");
}
