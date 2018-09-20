/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:19:17 by olbondar          #+#    #+#             */
/*   Updated: 2017/12/02 16:01:12 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		length;
	char	*str;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	while (s[length - 1] == ' '
	|| s[length - 1] == '\t' || s[length - 1] == '\n')
		length--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		length--;
	if (length <= 0)
		length = 0;
	str = (char*)malloc(length + 1);
	if (str == NULL)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < length)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
