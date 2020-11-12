/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 02:03:36 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 15:18:39 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_map *map)
{
	map->room = NULL;
	map->f_check = 0;
	map->f_color = -1;
	map->c_check = 0;
	map->c_color = -1;
	map->x = 0;
	map->y = 0;
	map->count = 0;
	map->sprite = 0;
	map->height_map = 0;
	map->max_w = 0;
	map->color = 0;
	map->len_ray = 0;
	map->tile = 0;
}

static void	init_place(t_place *place)
{
	place->x = 0;
	place->y = 0;
	place->px = 0;
	place->py = 0;
	place->fov = 0;
	place->dist = 0;
	place->snwe = 0;
	place->hy = 0;
}

static void	init_win(t_win *win)
{
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = 0;
	win->en = 0;
	win->bpp = 0;
	win->l_l = 0;
	win->win_w = 0;
	win->win_h = 0;
}

void		init_struct(t_all *all)
{
	all->i = 0;
	all->count_sprite = 0;
	all->screenshot = 0;
	init_image(&all->color);
	init_player(&all->plr);
	init_win(&all->win);
	init_place(&all->pl);
	init_sprits(all);
	init_key(&all->key);
	init_map(&all->map);
	init_image(&all->tx_ea);
	init_image(&all->tx_so);
	init_image(&all->tx_no);
	init_image(&all->tx_we);
	init_image(&all->tx_s);
	init_ray_sprite(&all->r_sp);
}
