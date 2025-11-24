/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:19:37 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 00:49:28 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithms.h"

/*
 * Quick sorts in O(n log n) complexity, much faster than my previous
 * bubble sort (O(n^2)). A good introduction to the algorithm here:
 * https://medium.com/@alejandro.itoaramendia/
 * quick-sort-a-complete-guide-4c0a7f86ed72
 * 
 * and here:
 * https://medium.com/@nathaldawson/
 * unraveling-quicksort-the-fast-and-versatile-sorting-algorithm-2c1214755ce9
 */
void	quick_sort_arr(int *arr, int low, int high)
{
	t_quick_sort	data;

	if (low >= high)
		return ;
	data.pivot = arr[(low + high) / 2];
	data.i = low;
	data.j = high;
	while (data.i <= data.j)
	{
		while (arr[data.i] < data.pivot)
			data.i++;
		while (arr[data.j] > data.pivot)
			data.j--;
		if (data.i <= data.j)
		{
			data.tmp = arr[data.i];
			arr[data.i] = arr[data.j];
			arr[data.j] = data.tmp;
			data.i++;
			data.j--;
		}
	}
	quick_sort_arr(arr, low, data.j);
	quick_sort_arr(arr, data.i, high);
}
