/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithms.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:02:22 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 18:50:00 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_ALGORITHMS_H
# define PS_ALGORITHMS_H

typedef struct s_quick_sort
{
	int	tmp;
	int	pivot;
	int	i;
	int	j;
}	t_quick_sort;

typedef struct s_node
{
	int		value;
	size_t	index;
}	t_node;

void	quick_sort_arr(int *arr, int low, int high);
void	quick_sort_nodes(t_node *arr, int low, int high);

#endif /* PS_ALGORITHMS_H */