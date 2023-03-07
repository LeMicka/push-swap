/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:05:32 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/01/13 12:23:51 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_list	set_args(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	if (argc == 2)
	{
		t_var->split = ft_split(argv[1], " ");
	}
	
}
