/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:39:30 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/09 10:34:29 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions(t_bounds *stack_a, t_bounds *stack_b)
{
	if (stack_b->head->order == 5)
	{
		make_pa(stack_a, stack_b);
		make_ra(stack_a);
	}
	else if (stack_b->head->order == 3)
	{	
		make_ra(stack_a);
		make_pa(stack_a, stack_b);
		make_sa(stack_a->head);
		make_rra(stack_a);
	}
	else if (stack_b->head->order == 4)
	{
		make_rra(stack_a);
		make_pa(stack_a, stack_b);
		make_ra(stack_a);
		make_ra(stack_a);
	}
	else if (stack_b->head->order == 2)
	{
		make_pa(stack_a, stack_b);
		make_sa(stack_a->head);
	}
}

void	put_last(t_bounds *stack_a, t_bounds *stack_b)
{
	while (stack_b->head != NULL)
	{
		actions(stack_a, stack_b);
		if (stack_b->head->order == 1)
			make_pa(stack_a, stack_b);
	}
}

void	sort_5(t_bounds *stack_a, t_bounds *stack_b)
{
	make_pb(stack_a, stack_b);
	make_pb(stack_a, stack_b);
	sort_3(stack_a);
	if (stack_b->head->order < stack_b->head->next->order)
		make_sb(stack_b->head);
	if (stack_a->head->order == 3)
	{
		make_pa(stack_a, stack_b);
		make_pa(stack_a, stack_b);
	}
	else if (stack_b->head->order == 3)
	{
		make_pa(stack_a, stack_b);
		make_sa(stack_a->head);
	}
	put_last(stack_a, stack_b);
}
