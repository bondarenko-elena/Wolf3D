/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:03:34 by adespond          #+#    #+#             */
/*   Updated: 2015/11/30 12:44:21 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	return (s2);
}
