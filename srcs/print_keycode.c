/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:39:46 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	print_keycode(int keycode)
{
	char	*ckeycode;

	ckeycode = ft_itoa(keycode);
	ft_putendl(ckeycode);
	free(ckeycode);
}
