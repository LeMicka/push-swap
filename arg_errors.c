/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:02:16 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/28 09:34:20 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief check_errors function
 * 
*/

int	check_errors(char **split)
{
	if (!are_ints(split))
	{
		return (0);
	}
	if (!null_arg(split))
	{
		return (0);
	}
	if (!are_dup(split))
	{
		return (0);
	}
	if (!number_too_big(split))
		return (0);
	return (1);
}

/**
 * @brief function to check if there are any duplicates in the stack
 * 
 */
int	are_dup(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief function to check if all the members of the stacks are integers
 * 
*/
int	are_ints(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] == '-' && ft_isdigit (split[i][j + 1]))
				j++;
			else
				if (!ft_isdigit (split[i][j]))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	number_too_big(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_atoi_long(split[i]) < -2147483648
			|| ft_atoi_long(split[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief check for Null arguments
 * 
 */
int	null_arg(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_strlen(split[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
