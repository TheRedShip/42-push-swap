/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:39:15 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 15:19:22 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	args_len(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
		i++;
	return (i);
}

char	**split_args(int *argc, char **argv, int *tofree)
{
	char	**split_args;

	split_args = ft_split_mult(argv[0], " \t\n");
	*argc = args_len(split_args) + 1;
	*tofree = 1;
	return (split_args);
}
