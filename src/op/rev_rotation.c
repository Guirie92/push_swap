/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:21:45 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 15:17:26 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rev_rotate(t_stack *s)
{
	int	val;

	if (s->size <= 2)
		return ;
	
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
