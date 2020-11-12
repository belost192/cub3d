/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:33:41 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 21:19:00 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			start_drow_h(t_all *all)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = (all->win.win_h * 2);
	while (i > 0)
	{
		while (y < all->win.win_h - 2)
		{
			ft_pixel_put(all, x, y++, 0x000000);
			i--;
		}
		y = 0;
		x = all->win.win_w;
	}
}

void			get_hy(t_all *all, double len, float i)
{
	float		a;
	float		z2;
	float		z;
	float		h;
	float		i2;

	h = (all->win.win_h * SC) / len;
	a = (all->win.win_h - h) / 2;
	z = a + h;
	i2 = i - a;
	z2 = z - a;
	all->pl.hy = 63 * i2 / z2;
}

static void		color_height(t_all *all, int i)
{
	while (all->pl.snwe[i] == 5)
	{
		if (i <= 1 || i == all->win.win_w)
		{
			all->pl.snwe[i] = 1;
			break ;
		}
		i--;
	}
	if (all->pl.snwe[i] == 2 || all->pl.snwe[i] == 3)
	{
		all->color.height = all->pl.snwe[i] == 2 ? (((int)all->pl.x % 64))
			: (((int)all->pl.y % 64));
		all->color.addr = all->pl.snwe[i] == 2 ?
		all->tx_no.addr : all->tx_ea.addr;
	}
	if (all->pl.snwe[i] == 1 || all->pl.snwe[i] == 4)
	{
		all->color.height = all->pl.snwe[i] == 1 ? (63 - ((int)all->pl.x % 64))
			: (63 - ((int)all->pl.y % 64));
		all->color.addr = all->pl.snwe[i] == 1 ?
			all->tx_so.addr : all->tx_we.addr;
	}
}

int				get_color(t_all *all, unsigned int i)
{
	char		*dst;
	int			color;

	color_height(all, i);
	dst = all->color.addr + (((int)all->pl.hy) * all->tx_no.l_l
		+ all->color.height * (all->tx_no.bpp / 8));
	color = *(int*)dst;
	return (color);
}

int				get_storona(t_all *all)
{
	int			i;

	i = 0;
	all->pl.px = (all->pl.x - cosf(all->plr.plrstart));
	all->pl.py = (all->pl.y - sinf(all->plr.plrstart));
	if (((int)all->pl.x / SC == (int)all->pl.px / SC
	&& (all->pl.y > all->pl.py)))
		return (i = 1);
	if (((int)all->pl.x / SC == (int)all->pl.px / SC
	&& (all->pl.y < all->pl.py)))
		return (i = 2);
	if (((int)all->pl.y / SC == (int)all->pl.py / SC
	&& (all->pl.x > all->pl.px)))
		return (i = 3);
	if (((int)all->pl.y / SC == (int)all->pl.py / SC
	&& (all->pl.x < all->pl.px)))
		return (i = 4);
	else
		return (5);
}
