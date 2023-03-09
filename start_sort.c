/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:41:12 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/09 14:11:50 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order(t_bounds *stack, t_stack *element)
{
	int		order;
	t_stack	*curent;

	curent = stack->head;
	order = 1;
	while (curent != NULL)
	{
		if (curent->order < element->order)
			order++;
		curent = curent->next;
	}
	return (order);
}

void	sort_3(t_bounds *stack_a)
{
	if (order(stack_a, stack_a->head) == 1)
	{
		if (order(stack_a, stack_a->head->next) == 3)
		{
			make_sa(stack_a->head);
			make_ra(stack_a);
		}
	}
	else if (order(stack_a, stack_a->head) == 2)
	{
		if (order(stack_a, stack_a->head->next) == 1)
			make_sa(stack_a->head);
		else
			make_rra(stack_a);
	}
	else if (order(stack_a, stack_a->head) == 3)
	{
		if (order(stack_a, stack_a->head->next) == 1)
			make_ra(stack_a);
		else
		{
			make_sa(stack_a->head);
			make_rra(stack_a);
		}	
	}
}

int	already_sorted(t_bounds *stack_a)
{
	t_stack	*curent;

	curent = stack_a->head;
	while (curent->next != NULL)
	{
		if (curent->order > curent->next->order)
			return (0);
		curent = curent->next;
	}
	return (1);
}

void	sorting(t_var *variables, t_bounds *stack_a, t_bounds *stack_b)
{
	if (already_sorted(stack_a) == 0)
	{
		if (variables->len == 2)
		{
			if (stack_a->head->order > stack_a->head->next->order)
			{
				make_sa(stack_a->head);
			}
		}
		else if (variables->len == 3)
			sort_3(stack_a);
		else if (variables->len <= 5)
			sort_5(stack_a, stack_b);
		else if (variables->len <= 100)
		{
			variables->parts = 3;
			sort_100(variables, stack_a, stack_b);
		}	
	}
}
