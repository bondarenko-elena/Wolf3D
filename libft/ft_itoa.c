/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:00:08 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/26 13:41:54 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_length(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			length;
	unsigned int	tmp;

	length = ft_length(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		length++;
	}
	if (!(str = ft_strnew(length)))
		return (NULL);
	str[--length] = tmp % 10 + '0';
	while (tmp /= 10)
		str[--length] = tmp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
