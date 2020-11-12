/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:20:07 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 17:10:55 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_check_len_map(t_all *all, char *argv)
{
	const int	fd = open(argv, O_RDONLY);
	char		*line;
	int			count;
	int			width;

	width = 0;
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((ft_memcmp(line, " ", 1) == 0) || (ft_memcmp(line, "1", 1) == 0))
		{
			count++;
			if ((width = ft_strlen(line)) > all->map.max_w)
				all->map.max_w = width;
		}
		free(line);
	}
	close(fd);
	all->map.height_map = count;
}

int				parse_r(t_all *all, char *line)
{
	line++;
	all->tx.r_check = 1;
	ft_skip_spaces(all, line);
	all->win.win_w = ft_kak_atoi(all, line);
	all->win.win_h = ft_kak_atoi(all, line);
	if (all->win.win_w > MAX_WIDTH_RESOLUTION)
		all->win.win_w = MAX_WIDTH_RESOLUTION;
	if (all->win.win_h > MAX_HEIGHT_RESOLUTION)
		all->win.win_h = MAX_HEIGHT_RESOLUTION;
	ft_skip_spaces(all, line);
	if (all->win.win_w <= 0 || all->win.win_h <= 0 || line[all->i] != '\0')
		return (error_handler(WRONG_ARG));
	return (0);
}

int				ft_parcer(t_all *all, char *line, int fd)
{
	all->i = 0;
	if (ft_memcmp(line, "R", 1) == 0)
		return (parse_r(all, line));
	else if (ft_memcmp(line, "NO", 2) == 0)
		return (parse_no(all, line));
	else if (ft_memcmp(line, "SO", 2) == 0)
		return (parse_so(all, line));
	else if (ft_memcmp(line, "WE", 2) == 0)
		return (parse_we(all, line));
	else if (ft_memcmp(line, "EA", 2) == 0)
		return (parse_ea(all, line));
	else if (ft_memcmp(line, "S", 1) == 0)
		return (parse_s(all, line));
	else if (ft_memcmp(line, "F", 1) == 0)
		return (ft_colors(all, line, 'F'));
	else if (ft_memcmp(line, "C", 1) == 0)
		return (ft_colors(all, line, 'C'));
	else if ((ft_memcmp(line, " ", 1) == 0) || (ft_memcmp(line, "1", 1) == 0))
		return (map_manager(fd, line, all));
	else if (ft_skip_spaces(all, line) && line != '\0')
		printf("error empty line");
	return (-1);
}
