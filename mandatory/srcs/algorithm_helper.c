/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:02:46 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 13:38:20 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	resolve_three(t_elem *stack)
{
	int	start;
	int	end;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	if (get_min_stack(stack).index == start && \
	get_max_stack(stack, -1).index == end)
		return ;
	if (get_min_stack(stack).index == start && \
	get_max_stack(stack, -1).index == end - 1)
	{
		ft_swap(stack, "sa\n");
		shift_up(stack, "ra\n");
	}
	if (get_max_stack(stack, -1).index == start)
		shift_up(stack, "ra\n");
	if (stack[start].num > stack[start + 1].num)
		ft_swap(stack, "sa\n");
	if (get_min_stack(stack).index == end)
		shift_down(stack, "rra\n");
}

int	get_op_for_topplace(t_elem *stack_a, int index, int reel)
{
	int	count_op;
	int	start;
	int	end;
	int	median;

	count_op = 0;
	start = get_start_stack(stack_a);
	end = get_end_stack(stack_a);
	median = start + ((end - start) / 2);
	if (index > median)
	{
		count_op = end - index + 1;
		if (reel == 1)
			count_op = -count_op;
	}
	else if (index <= median)
		count_op = index - start;
	return (count_op);
}

int	get_op_for_gplace(t_elem *a, t_elem *b, int index)
{
	int		count_op;
	int		coherence;
	t_elem	min_num_behind;

	count_op = 0;
	count_op += get_op_for_topplace(a, index, 0);
	if (get_min_stack(b).num > a[index].num \
	|| get_max_stack(b, -1).num < a[index].num)
		count_op += get_op_for_topplace(b, get_min_stack(b).index, 0);
	else
	{
		min_num_behind = get_min_above_tresh(b, a[index].num);
		count_op += get_op_for_topplace(b, b[min_num_behind.index].index, 0);
	}
	coherence = get_coherences(a, b, index);
	if (coherence < 0)
		coherence = -coherence;
	count_op = count_op - coherence;
	return (count_op + 1);
}

int	get_coherences(t_elem *stack_a, t_elem *stack_b, int index)
{
	int	op_a;
	int	op_b;
	int	dist;
	int	min;

	op_a = get_op_for_topplace(stack_a, index, 1);
	if (get_min_stack(stack_b).num > stack_a[index].num || \
	get_max_stack(stack_b, -1).num < stack_a[index].num)
		op_b = get_op_for_topplace(stack_b, get_min_stack(stack_b).index, 1);
	else
	{
		min = get_min_above_tresh(stack_b, stack_a[index].num).index;
		op_b = get_op_for_topplace(stack_b, min, 1);
	}
	dist = 0;
	if (op_a > 0 && op_b > 0)
		dist = ft_min(op_a, op_b);
	if (op_a < 0 && op_b < 0)
		dist = ft_max(op_a, op_b);
	return (dist);
}

int	get_best_op_index(t_elem *stack_a, t_elem *stack_b, int stack_size)
{
	int		i;
	int		cost;
	int		start;
	t_elem	minsort;

	start = get_start_stack(stack_a);
	i = start;
	minsort.num = -1;
	while (i < stack_size - 1)
	{
		cost = get_op_for_gplace(stack_a, stack_b, i);
		if (cost < minsort.num || minsort.num == -1)
		{
			minsort.num = cost;
			minsort.index = i;
		}
		i++;
	}
	return (minsort.index);
}
