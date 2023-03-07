/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:11:53 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/07 10:53:52 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_bounds *stack)
{
	if (stack != NULL && stack->head != stack->last)
	{
		stack->last->next = stack->head;
		stack->head->prev = stack->last;
		stack->head = stack->last;
		stack->last = stack->last->prev;
		stack->head->prev = NULL;
		stack->last->next = NULL;
	}
}

void	make_rra(t_bounds *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	make_rrb(t_bounds *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	make_rrr(t_bounds *stack_a, t_bounds *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
