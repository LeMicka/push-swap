/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:41:12 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/07 12:16:39 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_bounds *stack_a)
{
	if (stack_a->head->order == 1)
	{
		if (stack_a->head->next->order == 3)
		{
			make_sa(stack_a->head);
			make_ra(stack_a);
		}
	}
	else if (stack_a->head->order == 2)
	{
		if (stack_a->head->next->order == 1)
			make_sa(stack_a->head);
		else
			make_rra(stack_a);
	}
	else if (stack_a->head->order == 3)
	{
		if (stack_a->head->next->order == 1)
			make_ra(stack_a);
		else
		{
			make_sa(stack_a->head);
			make_rra(stack_a);
		}	
	}
}

void	sorting(t_var *variables, t_bounds *stack_a, t_bounds *stack_b)
{
	stack_b = NULL;

	if (variables->len == 2)
	{
		if (stack_a->head->order > stack_a->head->next->order)
		{
			make_sa(stack_a->head);
		}
	}
	else if (variables->len == 3)
		sort_3(stack_a);
}
