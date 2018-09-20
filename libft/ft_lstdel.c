/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:10:26 by adespond          #+#    #+#             */
/*   Updated: 2015/11/27 12:48:20 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*tmp;

	l = *alst;
	while (l != NULL)
	{
		tmp = l->next;
		(del)(l->content, l->content_size);
		free(l);
		l = tmp;
	}
	*alst = NULL;
}
