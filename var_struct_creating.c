/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_struct_creating.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:55:00 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/07 10:28:34 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_length(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	//ft_printf("%i\n", len);
	return (len);
}

char	**fill_split(int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_split(argv[1], ' '));
	}
	else
	{
		return (&argv[1]);
	}
}

int	fill_arg_type(int argc)
{
	if (argc == 2)
		return (1);
	else
		return (0);
}

t_var	*struct_init(t_var *variables)
{
	variables = (t_var *)malloc(sizeof(t_var));
	if (!variables)
		return (NULL);
	variables->split = NULL;
	variables->len = 0;
	variables->arg_type = 0;
	return (variables);
}
