/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:42:49 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 15:18:29 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	parse_op(char *op, t_elem *stack_a, t_elem *stack_b)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		push_stack(stack_b, stack_a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ft_swap_both(stack_a, stack_b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		shift_up(stack_a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		shift_up(stack_b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ft_double_shift(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		shift_down(stack_a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		shift_down(stack_b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ft_double_shift(stack_a, stack_b, 1);
	else
		return (-1);
	return (1);
}

void	process_operation(t_elem *stack_a, t_elem *stack_b, char *op)
{
	int	ret;

	if (op == NULL || ft_strlen(op) == 1)
		ret = -1;
	else
		ret = parse_op(op, stack_a, stack_b);
	if (op != NULL)
		free(op);
	if (ret == -1)
	{
		free(stack_a);
		free(stack_b);
		get_next_line(0, 1);
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	solve_stdin(t_elem *stack_a, t_elem *stack_b)
{
	int		ret;
	char	*line;
	int		first;

	ret = 1;
	while (ret)
	{
		line = get_next_line(0, 0);
		if (line == NULL)
			ret = 0;
		else
			process_operation(stack_a, stack_b, line);
	}
	first = 0;
	while (stack_b[first].index != -1 && stack_b[first].filled != 1)
		first++;
	if (is_sorted(stack_a) == 1 && stack_b[first].index == -1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
