/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:39:08 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		play_music(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 4 + 1;
	system("killall -9 afplay");
	if (random == 1)
		system("afplay  music/music1.mp3 &");
	if (random == 2)
		system("afplay  music/music2.mp3 &");
	if (random == 3)
		system("afplay  music/music3.mp3 &");
	if (random == 4)
		system("afplay  music/music4.mp3 &");
}
