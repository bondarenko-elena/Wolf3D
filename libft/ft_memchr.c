/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:51:45 by adespond          #+#    #+#             */
/*   Updated: 2015/11/27 12:49:31 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;
	unsigned char	c2;

	str = (unsigned char*)s;
	c2 = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (str[i] == c2)
			return (str + i);
		i++;
		n--;
	}
	return (NULL);
}
