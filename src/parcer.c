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

char	**ft_make_map(t_list **head, int count)
{
	t_list	*tmp = *head;
	char	**map = ft_calloc(count + 1, sizeof(char *));
	int		i = 0;

	while (tmp)
	{
		map[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	i = 0;
	ft_lstclear(head, &free);
	while (map[i])
		ft_putendl_fd(map[i++], 1);
	return (map);
}
	

char	**ft_read_map(char *argv)
{
	char		*line;
	t_list		*head;
	int			count;
	const int	fd = open(argv, O_RDONLY);
	
	line = 0;
	head = 0;
	count = 0;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		count++;
		line = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	count++;
	return (ft_make_map(&head, count));

}

void	ft_init_plr(t_all *all)
{
	t_place	place;

	ft_bzero(&place, sizeof(t_place));
	while (all->map[(int)place.y])
	{
		place.x = 0;
		while (all->map[(int)place.y][(int)place.x])
		{
			if (ft_strchr("NEWS", all->map[(int)place.y][(int)place.x]))
			{
				all->plr->plrX = place.x * SCALE;
				all->plr->plrY = place.y * SCALE;
				all->plr->dir = 3 * M_PI_2;
			}
			place.x++;
		}
		place.y++;
	}	
}

void	ft_draw_screen(t_all *all)
{
	t_place	place;

	all->win->img = mlx_new_image(all->win->mlx, 1000, 512);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bits_per_pixel,
		&all->win->line_length, &all->win->en);
	ft_bzero(&place, sizeof(t_place));
	place.y = 0;
	while (all->map[(int)place.y]) // от 
	{
		place.x = 0;
		while (all->map[(int)place.y][(int)place.x])
		{
			if (all->map[(int)place.y][(int)place.x] == '1')
				ft_scale_img(all, place);
			place.x++;
		}
		place.y++;
	} // до 
	ft_draw_plr(all, place);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_destroy_image(all->win->mlx, all->win->img);
}

void	draw_wall(t_all *all, t_place pos, float angel, int lenght2)
{
	const double hz = cosf(all->plr->plrStart - all->plr->dir); // угол между лучем и зрением игрока
	double	len = (double)lenght2 * hz; // длина луча (от игрока до стены)
	double column_height = 512 / lenght2;
	double	posx = 0 + angel; // позиция по X для отрисовки стен
	double	dStart = floor(len) + 64; // первый пиксель стены
	double	dEnd = floor(-len)  + 400; // последний пиксель стены

	if (dStart < 0)
	 	dStart = 1;
	if (dEnd > 512)
	 	dEnd = 511;

	while (dStart < dEnd)
	{
		ft_pixel_put(all, posx, dStart, 0xEBCB8B - len * 2);
		dStart++;

	}
}

void	ft_draw_plr(t_all *all, t_place pos)
{
	ft_pixel_put(all, all->plr->plrX, all->plr->plrY, 0x0000FF00);
	all->plr->plrStart = all->plr->dir - (M_PI_4);
	all->plr->plarEnd = all->plr->dir + (M_PI_4);
	float x = 0;
	while (all->plr->plrStart <= all->plr->plarEnd)	
	{
		pos.x = all->plr->plrX;
		pos.y = all->plr->plrY;
		float c = 0;
		double iy = 0;
		double ix = 0;
		double dist = 0;
		int i = 0;
		while (all->map[(int)(pos.y / SCALE)][(int)(pos.x / SCALE)] != '1')
		{
			c += 0.05;
			pos.x = pos.x + cos(all->plr->plrStart);
			pos.y = pos.y + sin(all->plr->plrStart);	
			i++;
			ft_pixel_put(all, pos.x, pos.y, 0xEBCB8B);
		}
		iy = pos.y - all->plr->plrY; // Длина катета
		ix = pos.x - all->plr->plrX; // Длина катета
		(dist) = floor(sqrt((iy * iy) + (ix * ix))); // Длина луча
		x += 1;
		// draw_wall(all, pos, x, i); 
		all->plr->plrStart += M_PI_2 / 1000;
	}
}



void            ft_pixel_put(t_all *data, int x, int y, int color)
{
    char    *dst;

    dst = data->win->addr + (y * data->win->line_length + x * (data->win->bits_per_pixel / 8));
    *(int*)dst = color;
}



int		ft_move(int keypress, t_all *all)
{
	t_place posit;
	posit.x = all->plr->plrX;
	posit.y = all->plr->plrY;
	mlx_clear_window(all->win->mlx, all->win->win);	
	if (keypress == 13)
		{
		all->plr->plrY += sin(all->plr->dir) * 4;
		all->plr->plrX += cos(all->plr->dir) * 4;
		}
		
	if (keypress == 1)
		{
		all->plr->plrY -= sin(all->plr->dir) * 4;
		all->plr->plrX -= cos(all->plr->dir) * 4;
		}
	if (keypress == 0)
		all->plr->plrX -= 1;
	if (keypress == 2)
		all->plr->plrX += 1;
	if (keypress == 12)
	{
		all->plr->dir -= 0.1;
	}
	if (keypress == 14)
		all->plr->dir += 0.1;
	if (keypress == 53)
		exit(0);
	ft_draw_screen(all);
	return(0);
	
}

void	ft_scale_img(t_all *all, t_place place)
{
	t_place	end;

	end.x = (place.x + 1) * SCALE;
	end.y = (place.y + 1) * SCALE;
	place.x *= SCALE;
	place.y *= SCALE;
	while (place.y < end.y)
	{
		while (place.x < end.x)
			ft_pixel_put(all, place.x++, place.y, 0x3B4252);
		place.x -= SCALE;
		place.y++;
	}
}


int main(int ac, char **av)
{
	t_plr	plr;
	t_key	key;
	t_win 	win;
	t_all	all;
	if (ac == 2)
		all.map = ft_read_map(av[1]);
	else
		ft_putendl_fd("Pritirmozi, pritormozi", 2);
	ft_bzero(&key, sizeof(t_key));
	all.key = &key;
	ft_bzero(&plr, sizeof(t_plr));
	all.plr = &plr;
	ft_init_plr(&all);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, ScreenWidth, ScreenHeight, "CUB2D");
	win.img = mlx_new_image(win.mlx, ScreenWidth, ScreenHeight);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.en);
	all.win = &win;
	ft_draw_screen(&all);
	mlx_hook(win.win, 2, 1L<<0, &ft_move, &all);
	mlx_loop(win.mlx);
}
