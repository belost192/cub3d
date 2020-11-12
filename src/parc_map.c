/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:48:10 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 15:17:18 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_map_around(t_all *all, int x, int y)
{
	if (y - 1 < 0 || x - 1 < 0 || all->map.room[y - 1][x] == ' '
		|| all->map.room[y][x - 1] == ' ' || (all->map.room[y][x + 1] != '\0'
		&& all->map.room[y][x + 1] == ' ') || (y + 1 < all->map.height_map
		&& all->map.room[y + 1][x] == ' ' && y >= all->map.height_map))
		error_msg("Error\nSpaces im map!\nDelete this!");
}

void			find_dir(t_all *all, t_place pl)
{
	if (all->map.room[(int)pl.y][(int)pl.x] == 'N')
	{
		all->plr.pov = 3 * M_PI_2;
	}
	if (all->map.room[(int)pl.y][(int)pl.x] == 'S')
	{
		all->plr.pov = M_PI_2;
	}
	if (all->map.room[(int)pl.y][(int)pl.x] == 'W')
	{
		all->plr.pov = M_PI;
	}
	if (all->map.room[(int)pl.y][(int)pl.x] == 'E')
	{
		all->plr.pov = 0;
	}
}

int				init_plr(t_all *all)
{
	t_place		pl;

	ft_bzero(&pl, sizeof(t_place));
	while ((int)pl.y < all->map.height_map)
	{
		pl.x = 0;
		while ((int)pl.x < all->map.max_w)
		{
			if (ft_strchr("NEWS", all->map.room[(int)pl.y][(int)pl.x]))
			{
				all->plr.plrx = (double)pl.x * SC + (SC / 2);
				all->plr.plry = (double)pl.y * SC + (SC / 2);
				find_dir(all, pl);
				check_map_around(all, pl.x, pl.y);
			}
			if (all->map.room[(int)pl.y][(int)pl.x] == '2'
				|| all->map.room[(int)pl.y][(int)pl.x] == '0')
				check_map_around(all, pl.x, pl.y);
			pl.x++;
		}
		pl.y++;
	}
	return (0);
}

void			check_trash_map(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	while (y < all->map.height_map)
	{
		x = 0;
		while (x < all->map.max_w)
		{
			if ((all->map.room[y][x] == ' ' || all->map.room[y][x] == '0' ||
				all->map.room[y][x] == '1' || all->map.room[y][x] == '2') ||
				((all->map.room[y][x] == 'N' || all->map.room[y][x] == 'W' ||
				all->map.room[y][x] == 'S' || all->map.room[y][x] == 'E') &&
				all->plr.plrflag != 1))
			{
				if (all->map.room[y][x] == 'N' || all->map.room[y][x] == 'W' ||
					all->map.room[y][x] == 'S' || all->map.room[y][x] == 'E')
					all->plr.plrflag = 1;
				x++;
			}
			else
				error_msg("Error\nmap!\nChange it!");
		}
		y++;
	}
}

int				check_map_rec(char **map, int max_height, int x, int y)
{
	if (map[y][x] == ' ' || y < 0 || x < 0 || map[y][x] == '\0'
		|| y >= max_height)
		return (-1);
	if (map[y][x] == '1' || map[y][x] == '.')
		return (1);
	map[y][x] = '.';
	return (check_map_rec(map, max_height, x - 1, y) &&
			check_map_rec(map, max_height, x + 1, y) &&
			check_map_rec(map, max_height, x, y - 1) &&
			check_map_rec(map, max_height, x, y + 1));
}
