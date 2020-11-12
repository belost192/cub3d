/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:51:29 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 15:08:58 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_textures_addr(t_all *all)
{
	all->tx_no.addr = mlx_get_data_addr(all->tx_no.img,
		&all->tx_no.bpp, &all->tx_no.l_l, &all->tx_no.en);
	all->tx_so.addr = mlx_get_data_addr(all->tx_so.img,
		&all->tx_so.bpp, &all->tx_so.l_l, &all->tx_so.en);
	all->tx_we.addr = mlx_get_data_addr(all->tx_we.img,
		&all->tx_we.bpp, &all->tx_we.l_l, &all->tx_we.en);
	all->tx_ea.addr = mlx_get_data_addr(all->tx_ea.img,
		&all->tx_ea.bpp, &all->tx_ea.l_l, &all->tx_ea.en);
	all->tx_s.addr = mlx_get_data_addr(all->tx_s.img,
		&all->tx_s.bpp, &all->tx_s.l_l, &all->tx_s.en);
	return (1);
}

static void	validate_parameters(t_all *all)
{
	if (all->tx_so.img == NULL)
		error_msg("Error\nSO TX!");
	if (all->tx_no.img == NULL)
		error_msg("Error\nNO TX!");
	if (all->tx_we.img == NULL)
		error_msg("Error\nWE TX!");
	if (all->tx_ea.img == NULL)
		error_msg("Error\nEA TX!");
	if (all->tx_s.img == NULL)
		error_msg("Error\nS TX!");
	if (all->map.c_color == -1)
		error_msg("Error\nC color!");
	if (all->map.f_color == -1)
		error_msg("Error\nF color!");
}

static int	sort_mx(t_all *all)
{
	all->tx_no.img = mlx_xpm_file_to_image(all->win.mlx,
		all->tx.str_no, &all->tx_no.width, &all->tx_no.height);
	all->tx_so.img = mlx_xpm_file_to_image(all->win.mlx,
		all->tx.str_so, &all->tx_so.width, &all->tx_so.height);
	all->tx_we.img = mlx_xpm_file_to_image(all->win.mlx,
		all->tx.str_we, &all->tx_we.width, &all->tx_we.height);
	all->tx_ea.img = mlx_xpm_file_to_image(all->win.mlx,
		all->tx.str_ea, &all->tx_ea.width, &all->tx_ea.height);
	all->tx_s.img = mlx_xpm_file_to_image(all->win.mlx,
		all->tx.str_s, &all->tx_s.width, &all->tx_s.height);
	validate_parameters(all);
	return (get_textures_addr(all) ? 1 : 0);
}

int			start_mlx(t_all *all)
{
	if (!(all->map.len_ray = (double *)malloc((all->win.win_w)
		* sizeof(double))))
		printf("Error malloc map\n");
	if (!(all->pl.snwe = (int *)malloc((all->win.win_w)
		* sizeof(double))))
		printf("Error malloc map\n");
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, all->win.win_w,
		all->win.win_h, "cub3d");
	all->win.img = mlx_new_image(all->win.mlx, all->win.win_w,
		all->win.win_h);
	mlx_get_data_addr(all->win.img,
		&all->win.bpp, &all->win.l_l, &all->win.en);
	all->tx_no.addr = NULL;
	sort_sprite(all);
	sort_mx(all);
	ft_draw_screen(all);
	if (all->screenshot == 1)
		return (make_screen(all));
	mlx_hook(all->win.win, 2, 1L << 0, &ft_move, all);
	mlx_loop(all->win.mlx);
	return (0);
}
