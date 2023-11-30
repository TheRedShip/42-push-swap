/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:37:55 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 13:26:57 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
			tab[i].num = ft_atoi(argv[i]);
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

int	get_start_stack(t_elem *stack)
{
	int	first;

	first = 0;
	while (stack[first].index != -1 && stack[first].filled != 1)
		first++;
	if (stack[first].index == -1)
		first--;
	return (first);
}

int	get_end_stack(t_elem *stack)
{
	int	end;

	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	return (end);
}
