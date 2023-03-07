/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:55:35 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/07 10:50:52 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_bounds *stack)
{
	t_stack	*tmp;

	if (stack != NULL && stack->head != stack->last)
	{
		tmp = stack->head->next;
		stack->head->prev = stack->last;
		stack->last->next = stack->head;
		stack->last = stack->head;
		stack->head->next = NULL;
		stack->head = tmp;
		stack->head->prev = NULL;
	}
}

void	make_ra(t_bounds *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	make_rb(t_bounds *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	make_rr(t_bounds *stack_a, t_bounds *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
