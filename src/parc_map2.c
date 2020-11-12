/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 05:02:30 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/10 23:24:36 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_map(t_all *all)
{
	char	**new_map;
	int		i;
	int		res;

	i = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * all->map.height_map)))
		error_msg("Error\nMalloc has heart attack");
	while (i < all->map.height_map)
	{
		if (!(new_map[i] = ft_strdup(all->map.room[i])))
			error_msg("Error\nFt_strdup has heart attack");
		++i;
	}
	init_plr(all);
	res = check_map_rec(new_map, all->map.height_map,
		(int)all->plr.plrx / SC, (int)all->plr.plry / SC);
	check_trash_map(all);
	if (all->plr.plrflag == 0)
		error_msg("Error\nHave no player on map!\n");
	i = -1;
	while (++i < all->map.height_map)
		free(new_map[i]);
	free(new_map);
	return (res);
}

int			map_manager(int fd, char *line, t_all *all)
{
	int		height;
	char	**map;

	height = 0;
	if ((map = (char **)malloc(sizeof(char *)
		* (all->map.height_map + 2))) == NULL)
		return (error_handler(MALLOC_MAP_ERROR));
	map[height++] = line;
	while ((get_next_line(fd, &map[height]) > 0))
		height++;
	if (add_white_space(map, all->map.height_map, all->map.max_w) < 0)
		return (error_handler(MALLOC_MAP_ERROR));
	all->map.room = map;
	all->map.room[height + 1] = NULL;
	validate_map(all, all->map.room);
	if ((check_map(all) == -1))
		error_msg("Error\nClose map!");
	if (map[all->map.height_map][0] != '\0')
		return (-1);
	return (1);
}

void		check_one_more_shit(char **line, int max_height)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (i < max_height)
	{
		if (ft_strlen(line[i]) == 0 && i < max_height)
			error_msg("Error\nHey make classic map!\nPlease!");
		i++;
	}
	if (line[max_height][0] == '\0')
	{
		while (line[max_height - 1][x])
		{
			if (line[max_height - 1][x] == '0' || line[max_height - 1][x] == 'S'
			|| line[max_height - 1][x] == '2' || line[max_height - 1][x] == 'N'
			|| line[max_height - 1][x] == 'W' || line[max_height - 1][x] == 'E')
				error_msg("Error\nOh shit we have zero in last line!\n\
					Change it please!");
			x++;
		}
	}
}

int			add_white_space(char **line, int max_height, int max_width)
{
	int		y;
	int		len;
	char	*new_str;

	y = 0;
	check_one_more_shit(line, max_height);
	while (y < max_height)
	{
		len = ft_strlen(line[y]);
		if (len != max_width)
		{
			if ((new_str = malloc(sizeof(char *) * (max_width + 1))) == NULL)
				error_msg("Error\nMalloc White spaces!\n");
			ft_strlcpy(new_str, line[y], len + 1);
			while (len != max_width)
				new_str[len++] = ' ';
			new_str[len] = '\0';
			free(line[y]);
			line[y] = new_str;
		}
		y++;
	}
	return (1);
}

void		validate_map(t_all *all, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (j == 0 || j == all->map.max_w - 1)
					error_msg("Error\nMap Error");
				if (i == 0 || i == all->map.height_map - 1)
					error_msg("Error\nMap Error");
				if (j + 1 < all->map.max_w && map[i][j + 1] == ' ')
					error_msg("Error\nMap Error");
				if (map[i][j - 1] == ' ' || map[i - 1][j] == ' ')
					error_msg("Error\nMap Error");
				if (i + 1 < all->map.height_map && map[i + 1][j] == ' ')
					error_msg("Error\nMap Error");
			}
		}
	}
}
