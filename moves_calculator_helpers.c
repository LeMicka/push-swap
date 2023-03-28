/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:26:41 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/27 12:53:46 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*init_moves(t_moves *fastest)
{
	fastest = malloc(sizeof(t_moves));
	fastest->b_moves = 21474;
	fastest->a_moves = 21474;
	fastest->index = -1;
	return (fastest);
}

void	assign_new_vals(t_moves *fastest, t_moves *curent)
{
	fastest->a_moves = curent->a_moves;
	fastest->b_moves = curent->b_moves;
	fastest->index = curent->index;
}

void	last_a_moves(t_bounds *stack_a)
{
	//ft_printf("ici");
	while (stack_a->head->order == stack_a->last->order + 1)
		make_rra(stack_a);
}

int	smallest_biggerr(t_bounds *stack_a, t_stack *to_push)
{
	t_stack	*curent;
	int		order;

	curent = stack_a->head;
	while (curent != NULL)
	{
		if (curent->order > to_push->order)
		{
			order = curent->order;
			break ;
		}
		curent = curent->next;
	}
	while (curent != NULL)
	{
		if (curent->order > to_push->order && curent->order < order)
			order = curent->order;
		curent = curent->next;
	}
	return (order);
}
