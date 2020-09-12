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
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include "../minilibx_mms_20200219/mlx.h"
# include <fcntl.h>
# include <stdio.h>
<<<<<<< HEAD



typedef	struct	s_map
{
				char **map;
}				t_map;

void	ft_make_map(void);
=======



typedef	struct	s_win
{
		void	*mlx;
		void	*win;	
		void	*img;
		void	*addr;
		int		line_l;
		int		bpp;
		int		en;
}				t_win;


typedef struct s_point
{
		int		i;
		int		j;
}				t_point;

typedef struct s_plr
{
		int		i;
		int		j;
}				t_plr;

typedef struct s_player
{
		int		i;
		int		j;
		char	pos;
		int		color;
}				t_player;

typedef struct s_all
{
		char	**map;
		t_win	*win;
		t_plr	*plr;
		t_player *player;
		t_point *point;

}				t_all;

void	ft_scale_img(t_win *win, t_point point, t_all *all);
void	ft_make_map(void);
void    ft_draw_player(t_all *all, t_plr *pl);

>>>>>>> cub2d
# endif
