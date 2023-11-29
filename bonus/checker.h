/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:59:12 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/29 15:18:11 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_elem {
	int		num;
	int		filled;
	int		index;
}	t_elem;

t_elem	*create_tab(int argc, char **argv, int boolean);
void	show_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
char	**split_args(int *argc, char **argv, int *tofree);
int		args_len(char **split_args);
int		is_sorted(t_elem *stack);
int		ft_handle_errors(int argc, char **argv);
void	solve_stdin(t_elem *stack_a, t_elem *stack_b);
void	push_stack(t_elem *stack_a, t_elem *stack_b);
void	shift_down(t_elem *stack);
void	shift_up(t_elem *stack);
void	ft_swap(t_elem *stack);
void	ft_swap_both(t_elem *stack_a, t_elem *stack_b);
void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up);
int		get_start_stack(t_elem *stack);
int		get_end_stack(t_elem *stack);
int		get_min_stack(t_elem *stack);

#endif