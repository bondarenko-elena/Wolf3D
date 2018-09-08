/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:05:23 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/26 12:14:42 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
 unsigned int i;

 i = 0;
 while (i < n)
 {
  if (((char*)s)[i] == (char)c)
   return ((char*)s + i);
  i++;
 }
 return (0);
}
