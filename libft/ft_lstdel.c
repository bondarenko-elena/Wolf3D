/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:02:08 by olbondar          #+#    #+#             */
/*   Updated: 2017/12/02 15:34:19 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;

	if (alst != NULL && *alst != NULL && del != NULL)
	{
		lst = *alst;
		while (lst != NULL)
		{
			del(lst->content, lst->content_size);
			free(lst);
			lst = lst->next;
		}
		*alst = NULL;
	}
}
