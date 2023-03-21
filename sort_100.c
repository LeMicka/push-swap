/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:27:36 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/21 11:23:34 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	pre_sort_first(t_bounds *a, t_bounds *b)
{
	if (b->head != NULL && b->head->next != NULL)
	{
		if (a->head->order > a->last->order && b->head->order < b->last->order)
		{
			make_rra(a);
			make_rb(b);
		}	
		if (b->head->order < b->head->next->order)
			make_sb(b->head);
	}
}

void	sort_and_push(t_bounds *stack_a, t_bounds *stack_b, int elem, int pt)
{
	int	i;

	i = 0;

	if (pt == 1 && elem < 2)
		make_pb(stack_a, stack_b);
	else
	{
		if (stack_a->head->order == stack_b->head->order - 1
			|| stack_a->head->order == stack_b->head->order + 1)
			make_pb(stack_a, stack_b);
		else if (stack_a->head->order == stack_b->last->order - 1
			|| stack_a->head->order == stack_b->last->order + 1)
		{
			make_pb(stack_a, stack_b);
			make_rb(stack_b);
		}
		else
			make_pb(stack_a, stack_b);
	}
}

void	push_last(t_var *vars, t_bounds *a, t_bounds *b, int pt)
{
	int	i;

	i = 0;
	while (i < (vars->len / vars->parts))
	{
		if (a->head->order <= (vars->len) - 3)
		{
			sort_and_push(a, b, i, pt);
			i++;
		}		
		else
			make_ra(a);
	}
}

void	push_to_b(t_var *vars, t_bounds *stack_a, t_bounds *stack_b, int pt)
{
	int	i;

	i = 0;
	while (i < (vars->len / vars->parts) - 1)
	{
		if (stack_a->head->order <= (vars->len / vars->parts) * pt - 1)
		{
			sort_and_push(stack_a, stack_b, i, pt);
			if (pt == 1)
				pre_sort_first(stack_a, stack_b);
			i++;
		}		
		else
			make_ra(stack_a);
	}
} */



void	sort_100(t_var *vars, t_bounds *stack_a, t_bounds *stack_b)
{
	int	i;

	i = 1;
	while (i < 6)
	{
		if (i == 5)
			push_last(vars, stack_a, stack_b, i);
		else
			push_to_b(vars, stack_a, stack_b, i);
		i++;
	}
	sort_3(stack_a);
}
