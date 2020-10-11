/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:29:55 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 15:15:47 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../minilibx_mms_20200219/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# define STEP 4
# define SCALE 16
# define M_PI_6 0.523598776
# define ScreenWidth 1000
# define ScreenHeight 520
# include <stdio.h>

typedef struct		s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		en;
	int		bits_per_pixel;
	int		line_length;
}					t_win;

typedef struct		s_plr
{
	int		plrX;
	int		plrY;
	float	dir;
	float	angel;
	float	plrStart;
	float	plarEnd;
}					t_plr;

typedef struct		s_place
{
	float	x;
	float	y;
	float	fov;
	float	dist;
}					t_place;

typedef struct		s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		q;
	int		e;
}					t_key;

typedef struct		s_all
{
	t_plr	*plr;
	t_win	*win;
	t_key	*key;
	char	**map;
}					t_all;


char	**ft_read_map(char *argv);
char	**make_map(t_list **head, int count);
void	ft_init_plr(t_all *all);
void	ft_draw_screen(t_all *all);
void	ft_draw_plr(t_all *all, t_place pos);
void	ft_draw_screen(t_all *all);
int		ft_move(int keypress, t_all *all);
void	ft_pixel_put(t_all *all, int x, int y, int color);
void	ft_scale_img(t_all *all, t_place place);
void	draw_wall(t_all *all, t_place pos, float angel, int lenght2);



# endif
