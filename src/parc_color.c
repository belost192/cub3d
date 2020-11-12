/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:11:08 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 15:15:32 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_color(char *line)
{
	int		i;
	int		len;

	i = 1;
	len = ft_strlen(line);
	if (len < 5)
		error_msg("Error\nColor!");
	while (line[++i])
	{
		if (line[i] == ',' && !ft_isdigit(line[i - 1]))
			error_msg("Error\nColor!");
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != ' ')
			error_msg("Error\nnColor!");
	}
	return (0);
}

int			ft_colors(t_all *all, char *line, char type)
{
	int		r;
	int		g;
	int		b;

	all->i += 2;
	r = ft_kak_atoi(all, line);
	all->i++;
	g = ft_kak_atoi(all, line);
	all->i++;
	b = ft_kak_atoi(all, line);
	ft_skip_spaces(all, line);
	if (line[all->i] != '\0' || r > 255 || g > 255 || b > 255 ||
									r < 0 || g < 0 || b < 0)
		return (-1);
	if (type == 'F')
	{
		all->map.f_color = r * 256 * 256 + g * 256 + b;
		all->map.f_check = 1;
	}
	else if (type == 'C')
	{
		all->map.c_color = r * 256 * 256 + g * 256 + b;
		all->map.c_check = 1;
	}
	return (validate_color(line));
}

int			parse_no(t_all *all, char *line)
{
	int		i;

	i = ft_strlen(line);
	if (ft_memcmp(line, "NO", 2) == 0)
	{
		if (!(all->tx.str_no = ft_strtrim(line, "NO ")))
			return (-1);
		all->tx.no_check = 1;
	}
	else
		return (error_handler(TEXTURE_FAILED));
	if (line[i - 1] != 'm')
		return (-1);
	if (!(valid_arg_format(all->tx.str_no, "xpm")))
		return (-1);
	return (0);
}
