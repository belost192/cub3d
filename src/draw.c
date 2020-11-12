/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:21:31 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/10 23:30:28 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		start_drow_w(t_all *all)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = (all->win.win_w * 2);
	while (i > 0)
	{
		while (x < all->win.win_w)
		{
			ft_pixel_put(all, x++, y, 0x000000);
			i--;
		}
		y = all->win.win_h - 2;
		x = 0;
	}
	start_drow_h(all);
}

static void		draw_floor(t_all *all, double dend, double posx, double ds)
{
	int			xx;

	xx = 0;
	while (dend < all->win.win_h - 1)
	{
		ft_pixel_put(all, posx, dend, all->map.f_color);
		dend++;
	}
	while (xx < ds)
	{
		ft_pixel_put(all, posx, xx, all->map.c_color);
		xx++;
	}
}

void			draw_wall(t_all *all, float posx, int lenght2)
{
	double		len;
	double		column_height;
	double		dstart;
	double		dend;
	int			color;

	len = (double)lenght2 * cosf(all->plr.plrstart - all->plr.pov);
	column_height = (all->win.win_h * SC) / len;
	dstart = (all->win.win_h / 2) - column_height / 2;
	dend = (all->win.win_h / 2) + column_height / 2;
	all->map.len_ray[(int)(posx - 1)] = len;
	if (dstart < 0)
		dstart = 1;
	if (dend > all->win.win_h)
		dend = all->win.win_h - 1;
	draw_floor(all, dend, (posx - 1), dstart);
	while (dstart < dend)
	{
		get_hy(all, len, dstart);
		color = get_color(all, (posx - 1));
		ft_pixel_put(all, (posx - 1), dstart, color);
		dstart++;
	}
}

void			ft_draw_plr(t_all *all)
{
	float		x;
	double		i;

	x = 0;
	all->plr.plrstart = all->plr.pov - (M_PI_6);
	all->plr.plarend = all->plr.pov + (M_PI_6);
	while (all->plr.plrstart <= all->plr.plarend)
	{
		all->pl.x = all->plr.plrx;
		all->pl.y = all->plr.plry;
		i = 0;
		while (all->map.room[(int)(all->pl.y / SC)][(int)(all->pl.x / SC)]
		!= '1' && all->map.room[(int)(all->pl.y / SC)][(int)(all->pl.x / SC)]
		!= ' ')
		{
			all->pl.x += cosf(all->plr.plrstart);
			all->pl.y += sinf(all->plr.plrstart);
			i++;
		}
		all->pl.snwe[(int)x] = get_storona(all);
		x += 1;
		draw_wall(all, x, i);
		all->plr.plrstart += (M_PI / 3) / all->win.win_w;
	}
}

void			ft_draw_screen(t_all *all)
{
	all->win.img = mlx_new_image(all->win.mlx, all->win.win_w, all->win.win_h);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.l_l, &all->win.en);
	ft_draw_plr(all);
	get_sprite(all);
	start_drow_w(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	mlx_destroy_image(all->win.mlx, all->win.img);
}
