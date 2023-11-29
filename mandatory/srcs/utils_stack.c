/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:27:17 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 13:40:23 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*create_tab(int argc, char **argv, int boolean)
{
	t_elem	*tab;
	int		i;

	tab = malloc(sizeof(t_elem) * (argc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (boolean == 1)
		{
			tab[i].num = ft_atoi(argv[i], NULL);
			tab[i].filled = 1;
		}
		else
		{
			tab[i].num = 0;
			tab[i].filled = 0;
		}
		tab[i].index = i;
		i++;
	}
	tab[i].index = -1;
	return (tab);
}

t_elem	get_min_stack(t_elem *stack)
{
	int	start;
	int	end;
	int	min;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	min = stack[start].index;
	while (start <= end)
	{
		if (stack[start].num < stack[min].num)
			min = stack[start].index;
		start++;
	}
	return (stack[min]);
}

t_elem	get_max_stack(t_elem *stack, int treshold)
{
	int	start;
	int	end;
	int	max;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	max = -1;
	while (start <= end)
	{
		if (max == -1 || ((stack[start].num > stack[max].num || \
		stack[max].filled == -1) && (treshold == -1 || \
		stack[start].num < treshold)))
			max = stack[start].index;
		start++;
	}
	return (stack[max]);
}

t_elem	get_min_above_tresh(t_elem *stack, int treshold)
{
	int	start;
	int	end;
	int	min;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	min = -1;
	while (start <= end)
	{
		if (stack[start].num > treshold && \
		(min == -1 || stack[start].num < stack[min].num))
			min = stack[start].index;
		start++;
	}
	if (min == -1)
		return (get_min_stack(stack));
	return (stack[min]);
}

int	is_sorted(t_elem *stack)
{
	int	i;

	i = 0;
	while (stack[i + 1].index != -1)
	{
		if (stack[i].num > stack[i + 1].num)
			return (-1);
		i++;
	}
	return (1);
}
