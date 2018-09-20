/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:07:07 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/26 12:20:20 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)ptr;
	while (i < num)
	{
		c[i] = (unsigned char)value;
		i++;
	}
	return (c);
}
