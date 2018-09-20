/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:50:32 by adespond          #+#    #+#             */
/*   Updated: 2015/11/30 13:16:25 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenght1;
	size_t	lenght2;
	size_t	ret;

	i = 0;
	lenght1 = ft_strlen(dst);
	lenght2 = ft_strlen(src);
	ret = lenght1 + lenght2;
	if (size > (lenght1 + 1))
	{
		while (i < (size - lenght1 - 1))
		{
			dst[lenght1 + i] = src[i];
			i++;
		}
		dst[lenght1 + i] = '\0';
	}
	if (size >= lenght1)
		return (ret);
	return (ret - (lenght1 - size));
}
