/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:18:00 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/26 14:27:41 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;
	size_t		length;

	str = (char*)s;
	length = ft_strlen(s);
	while (length != 0 && str[length] != (char)c)
		length--;
	if (str[length] == (char)c)
		return ((char*)&str[length]);
	return (NULL);
}
