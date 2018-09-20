/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:28:00 by adespond          #+#    #+#             */
/*   Updated: 2015/11/27 12:55:19 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		y;
	char	*occ;

	occ = 0;
	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			occ = (char *)s1 + i;
			y = 0;
			while (s1[i + y] == s2[y])
			{
				if (s2[y + 1] == '\0')
					return (occ);
				y++;
			}
			occ = 0;
		}
		i++;
	}
	return (0);
}
