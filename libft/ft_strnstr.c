/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:17:40 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/26 13:18:57 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			size;

	i = 0;
	size = ft_strlen(little);
	if (size == 0)
		return ((char*)big);
	while (big[i] != '\0' && (size + i) <= len)
	{
		j = 0;
		while (little[j] == big[j + i])
		{
			if (j == (size - 1))
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
