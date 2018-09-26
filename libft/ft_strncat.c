/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:16:08 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/25 17:33:55 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*str;
	size_t	k;
	size_t	i;
	size_t	j;

	str = dest;
	k = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && k < n)
	{
		str[i++] = src[j++];
		k++;
	}
	str[i] = '\0';
	return (dest);
}
