/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:50:35 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/02/20 10:22:51 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief wap the first 2 elements at the top of stack a.
 *  Do nothing if there is only one or no elements.
 * 
 */

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack != NULL && stack->next != NULL)
	{
		tmp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = tmp;
	}
}

/**
 * @brief make the functions that will be called and that print the action
 * 
 */

void	make_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	make_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	make_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
