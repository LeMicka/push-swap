/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:27:36 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/28 09:42:08 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_push(t_var *vars, t_bounds *stack_a, t_bounds *stack_b)
{
	while (vars->in_b < (vars->len) / 2)
	{
		if (stack_a->head->order <= (vars->len) / 2)
		{
			make_pb(stack_a, stack_b);
			vars->in_a--;
			vars->in_b++;
		}
		else
			make_ra(stack_a);
	}
	while (vars->in_a > 3)
	{
		if (stack_a->head->order < vars->len - 2)
		{
			make_pb(stack_a, stack_b);
			vars->in_a--;
			vars->in_b++;
		}
		else
			make_ra(stack_a);
	}
}

void	make_double_moves(t_bounds *a, t_bounds *b, t_moves	*fastest)
{
	while (fastest->a_moves > 0 && fastest->b_moves > 0)
	{
		make_rr(a, b);
		fastest->a_moves--;
		fastest->b_moves--;
	}
	while (fastest->a_moves < 0 && fastest->b_moves < 0)
	{
		make_rrr(a, b);
		fastest->a_moves++;
		fastest->b_moves++;
	}
}

void	push_fastest(t_bounds *a, t_bounds *b, t_moves	*fastest)
{
	make_double_moves(a, b, fastest);
	while (fastest->a_moves > 0)
	{
		make_ra(a);
		fastest->a_moves--;
	}
	while (fastest->b_moves > 0)
	{
		make_rb(b);
		fastest->b_moves--;
	}
	while (fastest->a_moves < 0)
	{
		make_rra(a);
		fastest->a_moves++;
	}
	while (fastest->b_moves < 0)
	{
		make_rrb(b);
		fastest->b_moves++;
	}
}

void	sort_bigs(t_var *vars, t_bounds *stack_a, t_bounds *stack_b)
{
	t_moves	*fastest;
	int		i;
	t_stack	*curent;

	i = 0;
	initial_push(vars, stack_a, stack_b);
	sort_3(stack_a);
	while (vars->in_b > 0)
	{
		fastest = fastest_to_move(vars, stack_a, stack_b);
		push_fastest(stack_a, stack_b, fastest);
		free(fastest);
		make_pa(stack_a, stack_b);
		curent = stack_a->head;
		vars->in_a++;
		vars->in_b--;
	}
	last_a_moves(stack_a);
	curent = stack_a->head;
}
