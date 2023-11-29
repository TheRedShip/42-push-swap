/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:24:53 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 13:42:21 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_elem *stack_a, t_elem *stack_b, char *str)
{
	int	first;
	int	end;

	first = 0;
	while (stack_a[first].filled != 1)
		first++;
	end = 0;
	while (stack_b[end].index != -1 && stack_b[end].filled != 1)
		end++;
	end--;
	stack_b[end].num = stack_a[first].num;
	stack_a[first].num = 0;
	stack_b[end].filled = 1;
	stack_a[first].filled = 0;
	ft_putstr_fd(str, 1);
}

void	shift_up(t_elem *stack, char *str)
{
	int	start;
	int	end;
	int	tempnum;
	int	tempnum2;
	int	i;

	start = 0;
	while (stack[start].index != -1 && stack[start].filled != 1)
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = end;
	tempnum = stack[i].num;
	while (i > start)
	{
		tempnum2 = stack[i - 1].num;
		stack[i - 1].num = tempnum;
		tempnum = tempnum2;
		i--;
	}
	stack[end].num = tempnum;
	ft_putstr_fd(str, 1);
}

void	shift_down(t_elem *stack, char *str)
{
	int	start;
	int	end;
	int	tempnum;
	int	tempnum2;
	int	i;

	start = 0;
	while (stack[start].index != -1 && stack[start].filled != 1)
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = start;
	tempnum = stack[i].num;
	while (i < end)
	{
		tempnum2 = stack[i + 1].num;
		stack[i + 1].num = tempnum;
		tempnum = tempnum2;
		i++;
	}
	stack[start].num = tempnum;
	ft_putstr_fd(str, 1);
}

void	ft_swap(t_elem *stack, char *msg)
{
	int	start;
	int	temp;

	start = get_start_stack(stack);
	temp = stack[start].num;
	stack[start].num = stack[start + 1].num;
	stack[start + 1].num = temp;
	ft_putstr_fd(msg, 1);
}

void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up)
{
	if (down_up == 1)
	{
		shift_down(stack_a, "");
		shift_down(stack_b, "");
		ft_putstr_fd("rrr\n", 1);
	}
	else
	{
		shift_up(stack_a, "");
		shift_up(stack_b, "");
		ft_putstr_fd("rr\n", 1);
	}
}
