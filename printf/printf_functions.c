/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:02:13 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/10/18 09:48:19 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr((char *)str);
	return (ft_strlen((char *)str));
}
