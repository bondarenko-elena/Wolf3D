/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:15:30 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/25 17:33:36 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	length;
	char	*map;

	i = 0;
	length = 0;
	if (s == NULL)
		return (NULL);
	while (s[length] != '\0')
	{
		length++;
	}
	map = (char*)malloc(length + 1);
	if (map == NULL)
		return (map);
	while (i < length)
	{
		map[i] = f(s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
