/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:16:23 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/08 23:06:43 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_handler(int error_num)
{
	if (error_num == MALLOC_MAP_ERROR)
		write(2, "Error\nmap's malloc return 0\n", 29);
	if (error_num == HANDLE_MAP_ERROR)
		write(2, "Error\nmap doesn't surrounded by wall\n", 38);
	if (error_num == WRONG_NUM_ARG)
		write(2, "Error\nwrong number of arguments\n", 33);
	if (error_num == WRONG_ARG)
		write(2, "Error\nwrong argument\n", 22);
	if (error_num == TEXTURE_FAILED)
		write(2, "Error\nwrong path to texture\n", 29);
	if (error_num == WRONG_SECOND_ARGUMENT)
		write(2, "Error\nsecond argument must be \"--save\"\n", 40);
	if (error_num == NO_PLAYER_ON_MAP)
		write(2, "Error\nhave no player on this map\n", 36);
	if (error_num == WRONG_FILE_FORMAT)
		write(2, "Error\nOh shit, file format is not .cub\n", 40);
	if (error_num == NO_FILE_TEXTURE)
		write(2, "Error\nOh shit, texture file is failed\n", 39);
	return (error_num);
}

void	error_msg(char *dst)
{
	ft_putstr_fd(dst, 1);
	ft_putchar_fd('\n', 1);
	exit(-1);
}
