/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:17:31 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 23:37:39 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	build_v_shape(t_stack *a, t_stack *b, int chunk_size, int *counter);
static void	pull_max_to_a(t_stack *a, t_stack *b);

void	k_sort(t_stack *a, t_stack *b, long n)
{
	int	chunk_size;
	int	counter;

	counter = 0;
	if (n <= K_SORT_THRESHOLD)
		chunk_size = CHUNK_SIZE_LO;
	else
		chunk_size = CHUNK_SIZE_HI;
	build_v_shape(a, b, chunk_size, &counter);
	pull_max_to_a(a, b);
}

static void	build_v_shape(t_stack *a, t_stack *b, int chunk_size, int *counter)
{
	int	top;

	while (a->size > 0)
	{
		top = lookup(a, 0);
		if (top <= *counter)
		{
			pb(a, b);
			rb(b);
			(*counter)++;
		}
		else if (top <= *counter + chunk_size)
		{
			pb(a, b);
			(*counter)++;
		}
		else
			ra(a);
	}
}

/*
 * Finds the largest/max number in the least, which happens to be == to
 * target since we normalized the values
 */
static void	find_max(t_stack *b, int target, int *max_idx)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (lookup(b, i) == target)
		{
			*max_idx = i;
			break ;
		}
		i++;
	}
}

// static void	pull_max_to_a(t_stack *a, t_stack *b)
// {
// 	int	max_idx;
// 	int	target;
// 	int	i;

// 	max_idx = 0;
// 	target = b->size - 1;
// 	i = 0;
// 	while (i < b->size)
// 	{
// 		find_max(b, target, &max_idx);
// 		if(max_idx <= b->size / 2)
// 			while(max_idx-- > 0)
// 				rb(b);
// 		else
// 			while(max_idx++ < b->size)
// 				rrb(b);
// 		pa(a, b);
// 		i++;
// 	}
// }
static void	pull_max_to_a(t_stack *a, t_stack *b)
{
	int	max_idx;
	int	target;

	while (b->size > 0)
	{
		max_idx = 0;
		target = b->size - 1;
		find_max(b, target, &max_idx);
		if(max_idx <= b->size / 2)
			while(max_idx > 0)
			{
				rb(b);
				max_idx--;
			}
		else
			while(max_idx < b->size)
			{
				rrb(b);
				max_idx++;
			}
		pa(a, b);
	}
}
// static void	pull_max_to_a(t_stack *a, t_stack *b)
// {
// 	int	max_idx;
// 	int	target;
// 	int	i;

// 	i = 0;
// 	while (i < b->size)
// 	{
// 		max_idx = 0;
// 		target = b->size - 1;
// 		find_max(b, target, &max_idx);
// 		if(max_idx <= b->size / 2)
// 			while(max_idx > 0)
// 			{
// 				rb(b);
// 				max_idx--;
// 			}
// 		else
// 			while(max_idx < b->size)
// 			{
// 				rrb(b);
// 				max_idx++;
// 			}
// 		pa(a, b);
// 		i++;
// 	}
// }
