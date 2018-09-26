/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:18:40 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/25 18:13:48 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	char	*b;
	char	*l;

	b = (char *)big;
	l = (char *)little;
	if (*l == '\0')
		return (b);
	while (*b != '\0')
	{
		i = 0;
		while (l[i] != '\0' && l[i] == b[i])
		{
			i++;
		}
		if (l[i] == '\0')
			return (b);
		b++;
	}
	return (NULL);
}
