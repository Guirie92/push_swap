/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:36 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/24 23:53:32 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	cleanup(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
}

int	stack_init(t_stack *a, t_stack *b, int count)
{
	a->arr = malloc(count * sizeof(int));
	if (!a->arr)
		return (EMEM_FAIL);
	b->arr = malloc(count * sizeof(int));
	if (!b->arr)
		return (EMEM_FAIL);
	a->head = 0;
	b->head = 0;
	a->size = count;
	b->size = 0;
	a->cap = count;
	b->cap = count;
	return (E_SUCESS);
}

void	exit_error(t_stack *a, t_stack *b)
{
	ft_printf(STDERR_FILENO, CLR_RED "Error\n" CLR_RST);
	cleanup(a, b);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_ps_data	data;

	ft_memset(&a, 0, sizeof (a));
	ft_memset(&b, 0, sizeof (b));
	if (argc < 2)
		exit_error(&a, &b);
	data.argc = argc;
	data.count = parse_count_digits(&data, argc, argv);
	ft_printf(STDOUT_FILENO, "count: %d\n", data.count); // DELETE
	if (data.count == -1)
		exit_error(&a, &b);
	if (stack_init(&a, &b, data.count) == EMEM_FAIL)
		exit_error(&a, &b);
	parse_args(&data, argv, a.arr, b.arr);
	return (EXIT_SUCCESS);
}
