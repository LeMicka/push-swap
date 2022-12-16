/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:55:42 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/24 17:06:45 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char *a = "salut c'est cool!";
// 	printf ("%s\n", a);
// 	printf ("%s\n", ft_memchr(a, 'o', 6));
// }