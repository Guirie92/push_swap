/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:24:02 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/26 02:07:44 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *a);
static void	sort_5(t_stack *a, t_stack *b);
static void	find_min(int *min_idx, int *min_val, t_stack *a);

void	sort_handler(t_stack *a, t_stack *b, long n)
{
	if (is_sorted(a))
		return ;
	if (n == 2)
		sa(a);
	else if (n == 3)
		sort_3(a);
	else if (n <= 5)
		sort_5(a, b);
	else
		chunk_sort(a, b, n);
}

/*
 * total combinations = 3! = 6 (0) -> sorted.
 * (1) [2, 1, 3] -> (sa)  -> [1, 2, 3]
 * (2) [3, 2, 1] -> (sa)  -> [2, 3, 1] -> (rra) -> [1, 2, 3]
 * (3) [3, 1, 2] -> (ra)  -> [1, 2, 3]
 * (4) [1, 3, 2] -> (sa)  -> [3, 1, 2] -> (ra)  -> [1, 2, 3]
 * (5) [2, 3, 1] -> (rra) -> [1, 2, 3]
 */
static void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = lookup(a, 0);
	mid = lookup(a, 1);
	bot = lookup(a, 2);
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

/*
 * It sends the two smallest nbrs to B, sorts 3 in A, and pushes the
 * smallest nbrs back to A:
 * (1) Finds, the smallest nbr in the array, then rotates it towards the
 * shorter side, and then pbs.
 * (2) Finds the smallest nbr in the updated array, rotates it to top with
 * the fewer moves, and sends it to B.
 * (3) sorts A
 * (4) Pa the two smallest nbrs (from larger to smaller) so that they are
 * placed correctly (sorted) in stack A.
 */
static void	sort_5(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	min_val;

	while (a->size > 3)
	{
		find_min(&min_idx, &min_val, a);
		if (min_idx <= a->size / 2)
			while (min_idx--)
				ra(a);
		else
			while (min_idx++ < a->size)
				rra(a);
		pb(a, b);
	}
	sort_3(a);
	while (b->size)
		pa(a, b);
}

static void	find_min(int *min_idx, int *min_val, t_stack *a)
{
	int	i;

	*min_idx = 0;
	*min_val = lookup(a, 0);
	i = 1;
	while (i < a->size)
	{
		if (lookup(a, i) < *min_val)
		{
			*min_val = lookup (a, i);
			*min_idx = i;
		}
		i++;
	}
}
