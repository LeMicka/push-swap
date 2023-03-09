/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:27:36 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/09 14:33:27 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(t_bounds *b)
{
	if (b->head != NULL && b->head->next != NULL)
	{
		if (b->head->order > b->head->next->order)
			make_sb(b->head);
		else if (b->head->order < b->last->order)
			make_rb(b);
	}
}

void	push_to_b(t_var *vars, t_bounds *stack_a, t_bounds *stack_b, int pt)
{
	int	i;

	i = 0;
	if (pt == vars->parts)
	{
		while (i < (vars->len / vars->parts) - 3)
		{
			if (stack_a->head->order <= (vars->len))
				make_pb(stack_a, stack_b);
			else
				make_ra(stack_a);
			pre_sort(stack_b);
			i++;
		}
	}
	else
	{
		while (i < (vars->len / vars->parts))
		{
			ft_printf("q= %i\n", ((vars->len / vars->parts) * pt));
			if (stack_a->head->order <= (vars->len / vars->parts) * pt)
			{
				make_pb(stack_a, stack_b);
				pre_sort(stack_b);
				i++;
			}		
			else
				make_ra(stack_a);
		}
	}
}

void	sort_100(t_var *vars, t_bounds *stack_a, t_bounds *stack_b)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		ft_printf("i= %i\n", i);
		push_to_b(vars, stack_a, stack_b, i);
		i++;
	}
}
