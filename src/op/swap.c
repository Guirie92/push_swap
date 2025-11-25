/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:21:45 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 18:39:22 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap(t_stack *s)
{
	int	i;
	int	j;
	int	tmp;

	if (s->size < 2)
		return ;
	i = s->head;
	j = ft_mod(s->head + 1, s->cap);
	tmp = s->arr[i];
	s->arr[i] = s->arr[j];
	s->arr[j] = tmp;
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
