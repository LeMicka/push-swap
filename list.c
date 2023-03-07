/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:34:00 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/07 10:49:19 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_list(t_bounds *a, int len, char **split)
{
	t_stack	*curent;
	int		i;

	i = 0;
	curent = (t_stack *)malloc(sizeof(t_stack));
	curent->prev = NULL;
	a->head = curent;
	while (i < len)
	{
		curent->data = ft_atoi(split[i]);
		curent->order = 0;
		if (i < len - 1)
		{
			curent->next = (t_stack *)malloc(sizeof(t_stack));
			curent->next->prev = curent;
			curent = curent->next;
			curent->next = NULL;
		}
		i++;
	}
	a->last = curent;
}

void	ft_add_order(t_bounds	*a, char **split, int len)
{
	t_stack	*curent;
	int		i;
	int		j;
	int		sup;

	i = 0;
	curent = a->head;
	while (i < len)
	{
		j = 0;
		sup = 0;
		while (j < len)
		{
			if (ft_atoi(split[i]) < ft_atoi(split[j]))
				sup++;
			j++;
		}
		curent->order = len - sup;
		curent = curent->next;
		i++;
	}
}

t_bounds	*create_list(char **split, int len)
{
	t_bounds	*a;

	a = NULL;
	a = (t_bounds *)malloc(sizeof(t_bounds));
	ft_fill_list(a, len, split);
	ft_add_order(a, split, len);
	return (a);
}

