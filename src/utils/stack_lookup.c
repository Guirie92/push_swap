/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lookup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 03:34:20 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 03:37:56 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
