/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:23:11 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/08 23:29:22 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_ray_sprite(t_ray_sp *r_sp)
{
	r_sp->sprite_x = 0;
	r_sp->sprite_y = 0;
	r_sp->invdet = 0;
	r_sp->transform_x = 0;
	r_sp->transform_y = 0;
	r_sp->sprite_screen_x = 0;
	r_sp->sprite_h = 0;
	r_sp->draw_start_y = 0;
	r_sp->draw_end_y = 0;
	r_sp->sprite_w = 0;
	r_sp->draw_start_x = 0;
	r_sp->draw_end_x = 0;
	r_sp->tex_x = 0;
	r_sp->tex_y = 0;
	r_sp->sprite = 0;
}

void			init_image(t_image *image)
{
	image->mlx = NULL;
	image->win = NULL;
	image->img = NULL;
	image->addr = 0;
	image->bpp = 0;
	image->l_l = 0;
	image->en = 0;
	image->width = 0;
	image->height = 0;
}

void			init_player(t_plr *plr)
{
	plr->plrstart = 0;
	plr->plarend = 0;
	plr->plrx = 0;
	plr->plry = 0;
	plr->pov = 0;
	plr->plrflag = 0;
	plr->fov = 0;
	plr->h_fov = 0;
	plr->n_line = 0;
}

void			init_key(t_key *key)
{
	key->w = 13;
	key->a = 0;
	key->s = 1;
	key->d = 2;
	key->q = 12;
	key->e = 14;
}

void			init_sprits(t_all *all)
{
	t_sprite	sprite;

	ft_bzero(&sprite, sizeof(t_sprite));
	all->sprite = &sprite;
}
