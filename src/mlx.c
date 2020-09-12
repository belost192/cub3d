/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:28:15 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 19:07:37 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_mms_20200219/mlx.h"
#include "../libft/libft.h"

int	ft_crate_pixel(void)
{
	void *mlx = NULL;
	void *win = NULL;
	int x = 100;
	int y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "test");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF7F50);
		}

	}
	mlx_loop(mlx);
}


