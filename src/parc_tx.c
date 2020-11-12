/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_tx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:55:09 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 15:08:18 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			valid_arg_format(char *filename, char *end)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if ((len = ft_strlen(filename)) > 4 &&
		filename[len - 1] == end[2] && filename[len - 2] == end[1] &&
		filename[len - 3] == end[0] && filename[len - 4] == '.')
		return (1);
	return (0);
}

int			parse_so(t_all *all, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "SO", 2) == 0)
	{
		if (!(all->tx.str_so = ft_strtrim(line, "SO ")))
			return (-1);
		all->tx.so_check = 1;
	}
	else
		return (error_handler(TEXTURE_FAILED));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(valid_arg_format(all->tx.str_so, "xpm")))
		return (-1);
	return (0);
}

int			parse_we(t_all *all, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "WE", 2) == 0)
	{
		if (!(all->tx.str_we = ft_strtrim(line, "WE ")))
			return (-1);
		all->tx.we_check = 1;
	}
	else
		return (error_handler(TEXTURE_FAILED));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(valid_arg_format(all->tx.str_we, "xpm")))
		return (-1);
	return (0);
}

int			parse_ea(t_all *all, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "EA", 2) == 0)
	{
		if (!(all->tx.str_ea = ft_strtrim(line, "EA ")))
			return (-1);
		all->tx.ea_check = 1;
	}
	else
		return (error_handler(TEXTURE_FAILED));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(valid_arg_format(all->tx.str_ea, "xpm")))
		return (-1);
	return (0);
}

int			parse_s(t_all *all, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "S", 1) == 0)
	{
		if (!(all->tx.str_s = ft_strtrim(line, "S ")))
			return (-1);
		all->tx.s_check = 1;
	}
	else
		return (error_handler(TEXTURE_FAILED));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(valid_arg_format(all->tx.str_s, "xpm")))
		return (-1);
	return (0);
}
