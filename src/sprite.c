/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:46:40 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 17:59:03 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		swap(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void		check_sprite(t_all *all)
{
	int			i;

	i = 0;
	all->map.tile = all->win.win_h > all->win.win_w ? \
	all->win.win_h / all->map.max_w : all->win.win_w / all->map.max_w;
	while (i < all->count_sprite)
	{
		all->sprite[i].angle = atan2(all->sprite[i].y - all->plr.plry, \
										all->sprite[i].x - all->plr.plrx);
		while (all->sprite[i].angle - all->plr.pov > M_PI)
			all->sprite[i].angle -= 2.0 * M_PI;
		while (all->sprite[i].angle - all->plr.pov < -M_PI)
			all->sprite[i].angle += 2.0 * M_PI;
		all->sprite[i].angle -= all->plr.pov;
		all->sprite[i].len = sqrt(pow(all->sprite[i].x - all->plr.plrx, 2) + \
							pow(all->sprite[i].y - all->plr.plry, 2));
		all->sprite[i].size = (all->map.tile / all->sprite[i].len) * \
										(all->win.win_w / 2) / tan(FOV / 2);
		all->sprite[i].x_ff = all->win.win_w / (FOV * (180 / M_PI)) * \
		((180 / M_PI * all->sprite[i].angle) + 30) - all->sprite[i].size / 2;
		all->sprite[i].y_ff = all->win.win_h / 2 - all->sprite[i].size / 2;
		all->sprite[i].step = all->tx_s.height / all->sprite[i].size;
		all->sprite[i].tex_pos = 0;
		i++;
	}
}

void			get_sprite(t_all *all)
{
	int			i;

	i = -1;
	while (++i < all->count_sprite)
		all->sprite[i].len = sqrt(
			pow((all->plr.plrx - all->sprite[i].x), 2)
			+ pow((all->plr.plry - all->sprite[i].y), 2));
	i = 0;
	while (i < all->count_sprite - 1)
	{
		if ((all->sprite)[i].len < (all->sprite)[i + 1].len)
		{
			swap(&(all->sprite)[i], &(all->sprite)[i + 1]);
			i = 0;
		}
		i++;
	}
	i = 0;
	check_sprite(all);
	while (i < all->count_sprite)
	{
		draw_sprite(all, all->sprite[i], i);
		i++;
	}
}

void			draw_sprite(t_all *all, t_sprite n, int i)
{
	int			j;
	int			tex_x;
	int			tex_y;

	i = -1;
	while (++i < n.size && n.size != 1.0 / 0.0)
	{
		if (n.x_ff + i > all->win.win_w || n.x_ff + i < 0 || \
							all->map.len_ray[i + (int)n.x_ff] < n.len)
			continue;
		tex_x = i / n.size * all->tx_s.width;
		n.tex_pos = 0;
		j = -1;
		while (++j < n.size)
		{
			tex_y = (unsigned int)n.tex_pos & (all->tx_s.height - 1);
			n.clr = (unsigned int *)(all->tx_s.addr + \
				(tex_y * all->tx_s.l_l + tex_x * (all->tx_s.bpp / 8)));
			n.tex_pos += n.step;
			if (n.y_ff + j > all->win.win_h || n.y_ff + j < 0 ||
			*n.clr == 0xFF000000)
				continue;
			ft_pixel_put(all, n.x_ff + i, n.y_ff + j, *n.clr);
		}
	}
}
