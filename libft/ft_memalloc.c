/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:04:31 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/25 17:22:52 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *)malloc(size);
	if (buff == NULL)
		return (NULL);
	while (i < size)
	{
		buff[i] = 0;
		i++;
	}
	return (buff);
}
