/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:39:26 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 21:31:15 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/cub3d.h"
#include "../minilibx_mms_20200219/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#define SCALE 16

char	**make_map(t_list **head, int size)
{
	char	**map = ft_calloc(size + 1, sizeof(char *));
	int i;
	t_list *tmp;
	
	i = -1;
	tmp = *head;
	while(tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

char **ft_open_map(char *av1)
{
	char 		*line = 0;
	t_list 		*head = 0;
	int			amount = 0;
	const int	fd = open(av1, O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		amount++;
		line = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	amount++;
	return (make_map(&head, ft_lstsize(head)));
}

void	draw_screen(t_all *all)
{
	t_point point;
	t_plr plr;
	t_win *win;

	t_win = all->win;

	// all->player = &player;


	ft_bzero(&point, sizeof(t_point));
	win->img = mlx_new_image(win->mlx, 640, 480);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	while(all->map[point.i])
	{
		point.j = 0;
		while(all->map[point.i][point.j])
		{
			if (all->map[point.i][point.j] == '1')
				 ft_scale_img(all->win, point, 0xFF8C00);
			// if (all->map[point.i][point.j] == 'N'|| all->map[point.i][point.j] == 'W' ||
			// all->map[point.i][point.j] == 'S'|| all->map[point.i][point.j] == 'E')
			// 	{
					
			// 		all->plr->i = point.i;
			// 		all->plr->j = point.j;
			// 		// player.i = point.i;
			// 		// player.j = point.j;
			// 		// all->player->color = 0xFFFFFF;
			// 		// printf("%d %d", all->player->i, all->player->j);
			// 		// ft_scale_img(all->win, point, all);
			// 		ft_draw_player(all, plr);

			// 	}	
			point.j++;
		}
		point.i++;
	}
		ft_draw_player(all, all->plr);
		mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
		mlx_destroy_image(win->mlx, win->img);
}

void	ft_draw_player(t_all *all, t_plr *pl)
{
	t_plr plr;
	plr = *all->plr;

	plr.start = plr.dir - M_PI_4;
	plr.end = plr.dir + M_PI_4;
	while (plr.start) < plr.end)
	{
		plr.j = plr->j;
		plr.i = plr->i;
		while (all->map[(int)(plr.j / SCALE)][(int)(plr.j / SCALE)] != '1')
		{
			plr.x += cos(plr.dir);
			plr.y += sin(plr.dir);
			ft_pixel_put(all->win, plr.y, 0x990099);
		}
		plr.start += M_PI_2 / 40;
	}
	
}

void	ft_pixel_put(t_win *win, int j, int int i, int color)
{
		char *dst;

		dst = win->addr + (x *(win->bpp / 8) + y * win->line_l);
		*(int)dst = color;
}

int	key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	if (key == 13)
		all->plr->i -= 1;
	if (key == 1)d
		all->plr->i += 1;
	if (key == 0)
		all->plr->j -= 1;
	if (key == 2)
		all->plr->j += 1;
	if (key == 53)
		exit(0);
	draw_screen(all);
	return (0);	
}

void	ft_scale_img(t_win *win, t_point point, t_all *all)
{
	t_point end;
	

	end.j = (point.j + 1) * SCALE;
	end.i = (point.i + 1) * SCALE;
	point.j *= SCALE;
	point.i *= SCALE;
	while (point.i < end.i)
	{
		while (point.j < end.j)
					mlx_pixel_put(win->mlx, win->win, point.j++, point.i, all->player->color);	
		point.j -= SCALE;
		point.i++;
	}
}



int main(int ac, char **av)
{
	t_win	win;
	t_all	all;
	t_plr	plr;

	if (ac == 2)
		all.map = ft_open_map(av[1]);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 640, 480, "cub2d");
	win.img = mlx_new_image(win.mlx, 640, 480);
	win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_l, &win.en);
	all.plr = &plr;
	all.win = &win;
	draw_screen(&all);
	mlx_hook(win.win, 2, (1L << 0), &key_press, &all);
	mlx_loop(win.mlx);
}
