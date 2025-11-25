/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rankify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 02:27:57 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 03:17:47 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	normalize_ranks(int *arr, size_t n)
{
	t_node	*nodes;
	size_t	i;

	nodes = malloc(sizeof(t_node) * n);
	if (!nodes)
		return (EMEM_FAIL);
	i = 0;
	while (i < n)
	{
		nodes[i].value = arr[i];
		nodes[i].index = i;
		i++;
	}
	quick_sort_nodes(nodes, 0, n - 1);
	i = 0;
	while (i < n)
	{
		arr[nodes[i].index] = i;
		i++;
	}
	free(nodes);
	return (E_SUCESS);
}
