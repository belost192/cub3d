#include "../minilibx_mms_20200219/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#define STEP 4
#define SIZE 16
#define M_PI_6 0.523598776
#include <stdio.h>

typedef struct		s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
}					t_win;

typedef struct		s_plr
{
	int		player_x;
	int		player_y;
	float	player_a;
	float	angel;
	float	player_start;
	float	player_end;
}					t_plr;

typedef struct		s_place
{
	float	x;
	float	y;
	float	fov;
	float		dist;
}					t_place;

typedef struct		s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		l_arrow;
	int		r_arrow;
}					t_key;

typedef struct		s_all
{
	t_plr	*plr;
	t_win	*win;
	t_key	*key;
	char	**map;
}					t_all;

char	**make_map(t_list **head, int count)
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

char	**ft_read_map(char *av)
{
	char		*line = 0;
	t_list		*head = 0;
	int			count = 0;
	const int	fd = open(av, O_RDONLY);

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		count += 1;
		line = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	count += 1;
	return (make_map(&head, count));
}

void	init_plr(t_all *all)
{
	t_place	place;

	ft_bzero(&place, sizeof(t_place));
	while(all->map[(int)place.y])
	{
		place.x = 0;
		while (all->map[(int)place.y][(int)place.x])
		{
			if (ft_strchr("NEWS", all->map[(int)place.y][(int)place.x]))
			{
				all->plr->player_x = place.x * SIZE;
				all->plr->player_y = place.y * SIZE;
				all->plr->player_a = 3 * M_PI_2;
			}
			place.x++;
		}
		place.y++;
	}
}


void            pixel_put(t_all *data, int x, int y, int color)
{
    char    *dst;

    dst = data->win->addr + (y * data->win->line_length + x * (data->win->bits_per_pixel / 8));
    *(int*)dst = color;
}

void	draw_wall(t_all *all, t_place pos, float angel, int lenght2)
{
// 	int y = 0;
// 	int x = 0;
// 	int lineWall = 0;
// 	int drawStart = 0;
// 	int drawEnd = 0;
// 	int count = 100;
// 	lineWall = (int)lenght * cos(all->plr->player_start);
// 	drawStart = -lineWall / 2 + 400;
// 	drawEnd = lineWall / 2 + 400;
// 	if (drawStart < 0)
// 		drawStart = 0;
// 	if (drawEnd > 800)
// 		drawEnd = 799;
// 	while (drawEnd > drawStart)
// 	{
// 		y = 0;
// 		while (y < 10)
// 		{
// 			pixel_put(all, drawStart, count, 0x000000FF);
// 			count += 1;
// 			y += 1;
// 		}
// 		drawStart += 1;
// 	}
// }
	const double dir = cosf(all->plr->player_start - all->plr->player_a); // угол между лучем и зрением игрока
	double	len = (double)lenght2 * dir; // длина луча (от игрока до стены)
	//float len = (float)lenght2;
	// float column_height = (float)512 / (int)len;
	double column_height = 512 / lenght2;
	// float i = 10;
	double	posx = 0 + angel; // позиция по X для отрисовки стен
	double	dStart = floor(len) + 64; // первый пиксель стены
	double	dEnd = floor(-len)  + 400; // последний пиксель стены
	// if (dStart % 2 != 0)
	// 	dStart -= 1;
	// if (dEnd % 2 != 0)
	// 	dEnd -= 1;
	if (dStart < 0)
	 	dStart = 1;
	if (dEnd > 512)
	 	dEnd = 511;
//	printf("start -- %f\n", dStart);
//	printf("end -- %f\n", dEnd);
	while (dStart < dEnd)
	{
//		if (dStart % 2 != 0)
//			pixel_put(all, posx, dStart, 0x0000FFFF);	
//		else
		//double posx = 500 - ((all->plr->player_start - all->plr->player_a) * 1000 / M_PI_2);
		//posx = 500 - ((all->plr->player_a - M_PI_4) * 1000 / M_PI_2);
		pixel_put(all, posx, dStart, 0x000000FF - len * 2);
		dStart++;
		//printf("start -- %f\n", dStart);
	}

	// void	draw_wall(t_all *all, t_place pos, int x, float angel, int lenght2)
// 	long column_height = 512 / (lenght2 * (cos(angel - all->plr->player_a)));
// 	float i = 10;
// 	float posx = 100 + x;
// 	long dStart = 100 - column_height / 2;
// 	long dEnd = 100 + column_height / 2;
// 	if (dStart < 0)
// 		dStart = 0;
// 	if (dEnd > 512)
// 		dEnd = 511;

// 	while (dStart < dEnd)
// 	{
// 		pixel_put(all, posx, dStart, 0x000000FF);
// 		dStart++;
// 	}
// }
}

void	draw_plr(t_all *all, t_place pos)
{
	pixel_put(all, all->plr->player_x, all->plr->player_y, 0x0000FF00);
	all->plr->player_start = all->plr->player_a - (M_PI_4);
	all->plr->player_end = all->plr->player_a + (M_PI_4);
	float x = 0;
	while (all->plr->player_start <= all->plr->player_end)	
	{
		pos.x = all->plr->player_x;
		pos.y = all->plr->player_y;
		float c = 0;
		double iy = 0;
		double ix = 0;
		double dist = 0;
		int i = 0;
		while (all->map[(int)(pos.y / SIZE)][(int)(pos.x / SIZE)] != '1')
		{
			c += 0.05;
			//pos.x = all->plr->player_x + c * cos(all->plr->player_start);
			//pos.y = all->plr->player_y + c * sin(all->plr->player_start);
			pos.x = pos.x + cosf(all->plr->player_start);
			pos.y = pos.y + sinf(all->plr->player_start);
			// if (all->plr->player_start == all->plr->player_a)
			// 	pixel_put(all, pos.x, pos.y, 0x0000FF00);		
			i += 1;
			pixel_put(all, pos.x, pos.y, 0x00FF0000);
		}
		iy = pos.y - all->plr->player_y; // Длина катета
		ix = pos.x - all->plr->player_x; // Длина катета
		(dist) = floor(sqrt((iy * iy) + (ix * ix))); // Длина луча
		x += 1;
		 draw_wall(all, pos, x, i);
		all->plr->player_start += M_PI_2 / ;
	}
}

void	scale_img(t_all *all, t_place place)
{
	t_place	end;

	end.x = (place.x + 1) * SIZE;
	end.y = (place.y + 1) * SIZE;
	place.x *= SIZE;
	place.y *= SIZE;
	while (place.y < end.y)
	{
		while (place.x < end.x)
			pixel_put(all, place.x++, place.y, 0xFFFFFF);
		place.x -= SIZE;
		place.y += 1;
	}
}

void	ft_draw_screen(t_all *all)
{
	t_place	place;

	all->win->img = mlx_new_image(all->win->mlx, 1000, 512);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bits_per_pixel,
		&all->win->line_length, &all->win->endian);
	ft_bzero(&place, sizeof(t_place));
	while (all->map[(int)place.y])
	{
		place.x = 0;
		while (all->map[(int)place.y][(int)place.x])
		{
			if (all->map[(int)place.y][(int)place.x] == '1')
				scale_img(all, place);
			place.x++;
		}
		place.y++;
	}
	draw_plr(all, place);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_destroy_image(all->win->mlx, all->win->img);
}

int		ft_move(int keypress, t_all *all)
{
	t_place posit;
	posit.x = all->plr->player_x;
	posit.y = all->plr->player_y;
	mlx_clear_window(all->win->mlx, all->win->win);	
	if (keypress == 13)
		all->plr->player_y -= 1;
	if (keypress == 1)
		all->plr->player_y += 1;
	if (keypress == 0)
		all->plr->player_x -= 1;
	if (keypress == 2)
		all->plr->player_x += 1;
	if (keypress == 12)
	{
		all->plr->player_a -= 0.1;
		printf("%f", all->plr->player_a);
	}
	if (keypress == 14)
		all->plr->player_a += 0.1;
	if (keypress == 53)
		exit(0);
	draw_screen(all);
	return(0);
	
}

int		main(int ac, char **av)
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
	init_plr(&all);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1000, 512, "CUB2D");
	win.img = mlx_new_image(win.mlx, 1000, 512);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
	all.win = &win;
	draw_screen(&all);
	mlx_hook(win.win, 2, 1L<<0, &move, &all);
	mlx_loop(win.mlx);
}
