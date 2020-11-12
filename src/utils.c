/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:05:00 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 15:08:39 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_scale_img(t_all *all)
{
	t_place	end;

	end.x = (all->pl.x + 1) * SC;
	end.y = (all->pl.y + 1) * SC;
	all->pl.x *= SC;
	all->pl.y *= SC;
	while (all->pl.y < end.y)
	{
		while (all->pl.x < end.x)
			ft_pixel_put(all, all->pl.x++, all->pl.y, 0x3B4252);
		all->pl.x -= SC;
		all->pl.y++;
	}
}

void		ft_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->win.addr + (y * data->win.l_l + x
	* (data->win.bpp / 8));
	*(int*)dst = color;
}

int			ft_skip_spaces(t_all *all, char *line)
{
	while ((line[all->i] == ' ' || line[all->i] == '\t' || line[all->i] == '\n')
	|| (line[all->i] == '\r' || line[all->i] == '\v' || line[all->i] == '\f'))
		all->i++;
	return (0);
}

int			ft_kak_atoi(t_all *all, char *line)
{
	int		num;

	num = 0;
	ft_skip_spaces(all, line);
	while (line[all->i] >= '0' && line[all->i] <= '9' && line[all->i] != ' ')
	{
		num = num * 10 + (line[all->i] - 48);
		all->i++;
	}
	return (num);
}
