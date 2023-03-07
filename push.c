/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:38:40 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/07 10:50:47 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_normal(t_bounds *src, t_bounds *dest)
{
	t_stack	*tmp;

	if (src->head == src->last)
		src->last = NULL;
	tmp = src->head->next;
	src->head->next = dest->head;
	dest->head->prev = src->head;
	dest->head = src->head;
	src->head = tmp;
	src->head->prev = NULL;
}

void	push_1element(t_bounds *src, t_bounds *dest)
{
	t_stack	*tmp;

	tmp = src->head->next;
	src->head->next = NULL;
	dest->head = src->head;
	src->head = tmp;
	dest->last = dest->head;
	src->head->prev = NULL;
	if (src->head == src->last)
		src->last = NULL;
}

void	push(t_bounds *src, t_bounds *dest)
{
	if (src != NULL)
	{
		if (dest->head != NULL)
		{
			push_normal(src, dest);
		}
		else
		{
			push_1element(src, dest);
		}
	}
}

void	make_pa(t_bounds *stack_a, t_bounds *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	make_pb(t_bounds *stack_a, t_bounds *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
