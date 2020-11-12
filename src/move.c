/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:06:23 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 17:42:08 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void		move_w(t_all *all)
{
	int				i;
	double			x;
	double			y;
	double			posx;
	double			posy;

	i = 0;
	posx = all->plr.plrx;
	posy = all->plr.plry;
	x = posx += cosf(all->plr.pov) * STEP * 5;
	y = posy += sinf(all->plr.pov) * STEP * 5;
	if (!(all->map.room[(int)(y / SC)][(int)(x / SC)] == '1'))
	{
		y = all->plr.plry += sinf(all->plr.pov) * STEP;
		x = all->plr.plrx += cosf(all->plr.pov) * STEP;
	}
}

static	void		move_s(t_all *all)
{
	int				i;
	double			x;
	double			y;
	double			posx;
	double			posy;

	i = 0;
	posx = all->plr.plrx;
	posy = all->plr.plry;
	x = posx -= cosf(all->plr.pov) * STEP * 5;
	y = posy -= sinf(all->plr.pov) * STEP * 5;
	if (!(all->map.room[(int)(y / SC)][(int)(x / SC)] == '1'))
	{
		y = all->plr.plry -= sinf(all->plr.pov) * STEP;
		x = all->plr.plrx -= cosf(all->plr.pov) * STEP;
	}
}

static	void		move_d(t_all *all)
{
	int				i;
	double			x;
	double			y;
	double			posx;
	double			posy;

	i = 0;
	posx = all->plr.plrx;
	posy = all->plr.plry;
	x = posx += cosf(all->plr.pov + M_PI_2) * STEP * 5;
	y = posy += sinf(all->plr.pov + M_PI_2) * STEP * 5;
	if (!(all->map.room[(int)(y / SC)][(int)(x / SC)] == '1'))
	{
		y = all->plr.plry += sinf(all->plr.pov + M_PI_2) * STEP;
		x = all->plr.plrx += cosf(all->plr.pov + M_PI_2) * STEP;
	}
}

static	void		move_a(t_all *all)
{
	int				i;
	double			x;
	double			y;
	double			posx;
	double			posy;

	i = 0;
	posx = all->plr.plrx;
	posy = all->plr.plry;
	x = posx -= cosf(all->plr.pov + M_PI_2) * STEP * 5;
	y = posy -= sinf(all->plr.pov + M_PI_2) * STEP * 5;
	if (!(all->map.room[(int)(y / SC)][(int)(x / SC)] == '1'))
	{
		y = all->plr.plry -= sinf(all->plr.pov + M_PI_2) * STEP;
		x = all->plr.plrx -= cosf(all->plr.pov + M_PI_2) * STEP;
	}
}

int					ft_move(int keypress, t_all *all)
{
	mlx_clear_window(all->win.mlx, all->win.win);
	if (keypress == all->key.w)
		move_w(all);
	if (keypress == all->key.s)
		move_s(all);
	if (keypress == all->key.a)
		move_a(all);
	if (keypress == all->key.d)
		move_d(all);
	if (keypress == all->key.q)
		all->plr.pov -= 0.1;
	if (keypress == all->key.e)
		all->plr.pov += 0.1;
	if (keypress == 53)
		exit(0);
	if (all->plr.pov > M_PI * 2)
		all->plr.pov -= M_PI * 2;
	if (all->plr.pov < 0)
		all->plr.pov += M_PI * 2;
	ft_draw_screen(all);
	return (0);
}
