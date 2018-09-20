/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:24:52 by adespond          #+#    #+#             */
/*   Updated: 2016/01/13 12:46:51 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		j;
	char	*s2;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	j = -1;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	if (len > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			len--;
			i++;
		}
	}
	s2 = ft_strnew(len);
	while (++j < len)
		s2[j] = s[i + j];
	return (s2);
}
