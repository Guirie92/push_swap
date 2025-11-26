/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:36 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/26 03:01:13 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	cleanup(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
}

static int	stack_init(t_stack *a, t_stack *b, int count)
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

static void	exit_error(t_stack *a, t_stack *b)
{
	ft_printf(STDERR_FILENO, "Error\n");
	cleanup(a, b);
	exit (EXIT_FAILURE);
}

static void	parse_normalize(t_ps_data *data, t_stack *a, t_stack *b,
		char **argv)
{
	int	i;

	i = 0;
	data->count = 0;
	data->count = parse_count_arr(data, data->argc, argv, i);
	if (data->count == -1)
		exit_error(a, b);
	if (stack_init(a, b, data->count) == EMEM_FAIL)
		exit_error(a, b);
	if (parse_args(data, argv, a->arr, b->arr) != E_SUCESS)
		exit_error(a, b);
	if (normalize_ranks(a->arr, (size_t)data->count) == EMEM_FAIL)
		exit_error(a, b);
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
	parse_normalize(&data, &a, &b, argv);
	sort_handler(&a, &b, data.count);
	cleanup(&a, &b);
	return (EXIT_SUCCESS);
}
