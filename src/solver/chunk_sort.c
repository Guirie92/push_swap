/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:17:31 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/26 02:45:13 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	build_v_shape(t_stack *a, t_stack *b, int chunk_size, int *counter);
static void	pull_max_to_a(t_stack *a, t_stack *b, int max_idx);

void	chunk_sort(t_stack *a, t_stack *b, long n)
{
	int	chunk_size;
	int	counter;
	int	max_idx;

	counter = 0;
	max_idx = 0;
	if (n <= CHUNK_SORT_THRESHOLD)
		chunk_size = CHUNK_SIZE_LO;
	else
		chunk_size = CHUNK_SIZE_HI;
	build_v_shape(a, b, chunk_size, &counter);
	pull_max_to_a(a, b, max_idx);
}

/*
 * Partition elements from A into chunks/bands and push them to B,
 * so that B ends up with a "V" distribution (when read top to bottom): 
 * larger/mid-band values are near the top while the smallest values are
 * rotated deeper into B. It uses `counter` + `chunk_size` to form bands.
 * 
 * Key idea:
 * Items with rank <= *counter are pushed then rotated (pb + rb),
 * which sends the smallest ranks away from B's top for faster retrieval in
 * the "pull max to A" phase.
 * 
 * DETAILED:
 *   Move all elements from stack A to stack B in chunked bands. Elements are
 *   classified by their rank (lookup(a,0) returns rank: 0 = smallest):
 * 
 *     - rank <= *counter: --> pb(a,b); rb(b)
 *         push to B then rotate B (pb, rb) so these
 *         smallest elements accumulate
 *         deeper in B (away from the top)
 * 
 *     - rank <= *counter + chunk_size: --> pb(a,b)
 *         push to B (pb) near B's top
 * 
 *     - else: --> ra(a)
 *         skip this element for now and revisit later
 */
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

static void	pull_max_to_a(t_stack *a, t_stack *b, int max_idx)
{
	int	target;

	while (b->size > 0)
	{
		max_idx = 0;
		target = b->size - 1;
		find_max(b, target, &max_idx);
		if (max_idx <= b->size / 2)
		{
			while (max_idx > 0)
			{
				rb(b);
				max_idx--;
			}
		}
		else
		{
			while (max_idx < b->size)
			{
				rrb(b);
				max_idx++;
			}
		}
		pa(a, b);
	}
}
