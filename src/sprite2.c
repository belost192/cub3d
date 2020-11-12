/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 04:18:14 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/10 21:36:44 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		make_sprite_list(t_all *all, t_place pl)
{
	t_sprite	*sprite;
	int			count;

	count = 0;
	if (!(sprite = (t_sprite *)malloc((all->count_sprite + 1)
		* sizeof(t_sprite))))
		printf("Error malloc map\n");
	if (all->count_sprite)
	{
		while (count < all->count_sprite)
		{
			((t_sprite *)sprite)[count] = all->sprite[count];
			count++;
		}
		free(all->sprite);
	}
	all->sprite = sprite;
	all->sprite[count].x = (double)pl.x * SC + (SC / 2);
	all->sprite[count].y = (double)pl.y * SC + (SC / 2);
	return (1);
}

int				sort_sprite(t_all *all)
{
	t_place		pl;

	ft_bzero(&pl, sizeof(t_place));
	while ((int)pl.y < all->map.height_map)
	{
		pl.x = 0;
		while ((int)pl.x < all->map.max_w)
		{
			if (ft_strchr("2", all->map.room[(int)pl.y][(int)pl.x]))
			{
				make_sprite_list(all, pl);
				all->count_sprite += 1;
			}
			pl.x++;
		}
		pl.y++;
	}
	return (0);
}
