/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:02:22 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/26 02:05:59 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVER_H
# define PS_SOLVER_H

# include "push_swap.h"
# define CHUNK_SORT_THRESHOLD 100
# define CHUNK_SIZE_LO 15
# define CHUNK_SIZE_HI 30

typedef struct s_stack	t_stack;

void	sort_handler(t_stack *a, t_stack *b, long n);
void	chunk_sort(t_stack *a, t_stack *b, long n);

#endif /* PS_SOLVER_H */