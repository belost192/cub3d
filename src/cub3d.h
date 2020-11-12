/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:29:55 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 00:49:51 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_mms/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define STEP 4
# define SC 64
# define M_PI_6 0.523598776

# define MAX_WIDTH_RESOLUTION 2560
# define MAX_HEIGHT_RESOLUTION 1400

# define NO_FILE_TEXTURE 111
# define WRONG_FILE_FORMAT 222
# define MAX_HEIGHT 2160/2
# define MAX_WIDTH 3840/2
# define MALLOC_MAP_ERROR -1
# define HANDLE_MAP_ERROR -2
# define PARSE_CUB_ERROR -3
# define WITHOUT_ARG_ERROR -4
# define WRONG_NUM_ARG -5
# define WRONG_ARG -6
# define TEXTURE_FAILED -7
# define WRONG_SECOND_ARGUMENT -8
# define NO_PLAYER_ON_MAP -9
# define SIZE 162
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define L_ARROW 65361
# define R_ARROW 65363
# define MS 0.1
# define RS 0.05
# define FOV 60 * (M_PI / 180)

# define FALSE 0
# define TRUE 1
# define SPRITE 2
# define OUT_OF_MAP 3

typedef struct		s_image
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					en;
	int					bpp;
	int					l_l;
	int					width;
	int					height;
}					t_image;

typedef struct		s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*img2;
	void				*addr;
	int					en;
	int					bpp;
	int					l_l;
	int					win_w;
	int					win_h;
}					t_win;

typedef struct		s_plr
{
	float				plrx;
	float				plry;
	float				pov;
	int					h_fov;
	float				n_line;
	float				plrstart;
	float				plarend;
	double				fov;
	int					plrflag;

}					t_plr;

typedef struct		s_place
{
	double				px;
	double				py;
	double				x;
	double				y;
	float				fov;
	float				dist;
	int					*snwe;
	double				hy;
}					t_place;

typedef struct		s_key

{
	int					w;
	int					s;
	int					a;
	int					d;
	int					q;
	int					e;
}					t_key;

typedef struct		s_sprite
{
	int					i;
	double				x;
	double				y;
	double				len;
	double				x_off;
	double				y_off;
	double				angle;
	double				size;
	double				x_ff;
	double				y_ff;
	double				step;
	double				tex_pos;
	unsigned int		*clr;
}					t_sprite;

typedef struct		s_tx
{
	char				*str_no;
	char				*str_so;
	char				*str_we;
	char				*str_ea;
	char				*str_s;
	int					no_check;
	int					so_check;
	int					we_check;
	int					ea_check;
	int					s_check;
	int					r_check;
}					t_tx;

typedef struct		s_map
{
	char				**room;
	int					f_color;
	int					c_color;
	int					f_check;
	int					c_check;
	int					y;
	int					x;
	int					count;
	int					sprite;
	int					height_map;
	int					max_w;
	int					color;
	double				*len_ray;
	double				x22;
	int					w22;
	double				tile;
}					t_map;

typedef struct		s_ray_sp
{
	double				sprite_x;
	double				sprite_y;
	double				invdet;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_h;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_w;
	int					draw_start_x;
	int					draw_end_x;
	int					tex_x;
	int					tex_y;
	int					sprite;
}					t_ray_sp;

typedef struct		s_all
{
	int					i;
	int					count_sprite;
	t_plr				plr;
	t_win				win;
	t_key				key;
	t_map				map;
	t_image				tx_we;
	t_image				tx_ea;
	t_image				tx_so;
	t_image				tx_no;
	t_image				tx_s;
	t_tx				tx;
	t_place				pl;
	t_sprite			*sprite;
	t_ray_sp			r_sp;
	int					screenshot;
	t_image				color;
}					t_all;
/*
** init2.c
*/
void				init_ray_sprite(t_ray_sp *r_sp);
void				init_image(t_image *image);
void				init_player(t_plr *plr);
void				init_key(t_key *key);
void				init_sprits(t_all *all);
int					main(int ac, char **av);
void				init_struct(t_all *all);
int					start_mlx(t_all *all);
void				ft_scale_img(t_all *all);
int					ft_move(int keypress, t_all *all);
void				ft_draw_plr(t_all *all);
int					ft_parcer(t_all *all, char *line, int fd);
void				ft_init_plr(t_all all);
void				ft_pixel_put(t_all *data, int x, int y, int color);
void				ft_draw_screen(t_all *all);
void				draw_wall(t_all *all, float angel, int lenght2);
int					error_handler(int error_num);
/*
** utils.c
*/
int					ft_skip_spaces(t_all *all, char *line);
int					ft_kak_atoi(t_all *all, char *line);
/*
** parce_tx.c
*/
int					parse_no(t_all *all, char *line);
int					parse_so(t_all *all, char *line);
int					parse_we(t_all *all, char *line);
int					parse_ea(t_all *all, char *line);
int					parse_s(t_all *all, char *line);
int					valid_arg_format(char *filename, char *end);
int					ft_colors(t_all *all, char *line, char type);
void				check_map_around(t_all *all, int x, int y);
int					init_plr(t_all *all);
void				check_trash_map(t_all *all);
int					get_storona(t_all *all);
void				error_msg(char *dst);
void				validate_map(t_all *all, char **map);
void				check_one_more_shit(char **line, int max_height);
int					add_white_space(char **line, int max_height, int max_width);
int					map_manager(int fd, char *line, t_all *all);
int					check_map(t_all *all);
int					check_map_rec(char **map, int max_height, int x, int y);
void				ft_check_len_map(t_all *all, char *argv);
int					parse_r(t_all *all, char *line);
void				raycasting(t_all *all);
void				check_wall(t_all *all);
int					check_map_field(char **map, int y, int x);
void				c_step(t_all *all);
void				pixel_put(t_all *data, int x, int y, int color);
int					get_color(t_all *all, unsigned int i);
void				get_hy(t_all *all, double len, float i);
int					sort_sprite(t_all *all);
void				get_sprite(t_all *all);
void				draw_sprite(t_all *all, t_sprite n, int i);
int					get_color_sprite(t_all *all);
int					make_screen(t_all *all);
void				start_drow_h(t_all *all);
#endif
