/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:34:53 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/28 09:23:55 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_abs(t_moves	*moves)
{
	int	a;
	int	b;

	a = moves->a_moves;
	b = moves->b_moves;
	if (a < 0)
		a = a * (-1);
	if (b < 0)
		b = b * (-1);
	return (a + b);
}

int	a_moves(t_var *vars, t_bounds *stack_a, t_stack *to_push)
{
	t_stack	*curent;
	int		smallest_bigger;
	int		i;

	smallest_bigger = smallest_biggerr(stack_a, to_push);
	curent = stack_a->head;
	i = 0;
	while (curent != NULL)
	{
		if (curent->order == to_push->order + 1)
			break ;
		else if (curent->order == smallest_bigger)
			break ;
		curent = curent->next;
		i++;
	}
	if (curent == NULL)
		return (0);
	if (i > vars->in_a / 2)
		return (((vars->in_a - i) * (-1)));
	else
		return (i);
}

int	b_moves(t_var *vars, int i)
{
	if (i > vars->in_b / 2)
		return (((vars->in_b - i) * (-1)));
	else
		return (i);
}

t_moves	*moves_needed(t_var *vars, t_bounds *stack_a, t_bounds *stack_b)
{
	t_stack	*curent;
	t_moves	*curent_moves;
	t_moves	*fastest;
	int		i;

	curent_moves = NULL;
	fastest = NULL;
	curent_moves = malloc(sizeof(t_moves));
	fastest = init_moves(fastest);
	curent = stack_b->head;
	i = 0;
	while (curent != NULL)
	{
		curent_moves->a_moves = a_moves(vars, stack_a, curent);
		curent_moves->b_moves = b_moves(vars, i);
		curent_moves->index = i;
		if (val_abs(curent_moves) < val_abs(fastest))
			assign_new_vals(fastest, curent_moves);
		i++;
		curent = curent->next;
	}
	free(curent_moves);
	return (fastest);
}

t_moves	*fastest_to_move(t_var *vars, t_bounds *a, t_bounds *b)
{
	t_moves	*fastest;

	fastest = moves_needed(vars, a, b);
	return (fastest);
}
