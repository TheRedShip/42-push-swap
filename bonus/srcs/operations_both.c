/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:18:30 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 15:18:42 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_swap_both(t_elem *stack_a, t_elem *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up)
{
	if (down_up == 1)
	{
		shift_down(stack_a);
		shift_down(stack_b);
	}
	else
	{
		shift_up(stack_a);
		shift_up(stack_b);
	}
}
