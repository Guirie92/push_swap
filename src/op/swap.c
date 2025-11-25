/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:21:45 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 15:08:05 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_stack *s)
{
	int	i0;
	int	i1;
	int	tmp;

	if (s->size < 2)
		return ;
	i0 = s->head;
	i1 = ft_mod(s->head + 1, s->cap);
	tmp = s->arr[i0];
	s->arr[i0] = s->arr[i1];
	s->arr[i1] = tmp;
}

void	sa(t_stack *a)
{
	swap(a);
	op_print("sa");
}

void	sb(t_stack *b)
{
	swap(b);
	op_print("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	op_print("ss");
}
