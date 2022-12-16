/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:20:40 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/10/19 16:24:11 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_print_str(const char *str);
int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_print_addr(uintptr_t ptr);
int	ft_printnbr(int n);
int	ft_printunbr(unsigned int n);
int	ft_printhex(unsigned int ptr, char id);

#endif