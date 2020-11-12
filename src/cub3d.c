/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:39:26 by chnikia           #+#    #+#             */
/*   Updated: 2020/11/11 17:10:46 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_params(t_all *all)
{
	if (all->tx.no_check == 1 && all->tx.so_check == 1 && all->tx.we_check == 1
		&& all->tx.ea_check == 1 && all->tx.s_check == 1 &&
		all->tx.r_check == 1 && all->map.f_check == 1 && all->map.c_check == 1)
		return (1);
	printf("%d", all->tx.no_check);
	printf("%d", all->tx.so_check);
	printf("%d", all->tx.we_check);
	printf("%d", all->tx.ea_check);
	printf("%d", all->tx.s_check);
	printf("%d", all->tx.r_check);
	printf("%d", all->map.f_check);
	printf("%d", all->map.c_check);
	return (0);
}

static int		ft_scan_map(t_all *all, char **argv)
{
	char		*line;
	const int	fd = open(argv[1], O_RDONLY);
	int			n;
	int			num_of_args;

	num_of_args = 0;
	while ((get_next_line(fd, &line) > 0))
	{
		if (*line)
		{
			num_of_args++;
			n = ft_parcer(all, line, fd);
			if (n < 0)
				return (error_handler(WRONG_ARG));
			if (n == 1)
				break ;
		}
		free(line);
	}
	if ((check_params(all)) <= 0)
		error_msg("Error\nNo someone flag!");
	if (num_of_args != 9)
		error_msg("Error\nError params!");
	close(fd);
	return (0);
}

static int		validate_argv(int ac, char **av)
{
	int bmp;
	int len;

	bmp = FALSE;
	if (ac == 1)
		error_msg("Error\nThe first argument must be the configuration file.!");
	if (ac >= 2)
	{
		len = ft_strlen(av[1]) - 4;
		if (len <= 0 || ft_memcmp(av[1] + len, ".cub\0", 5) != 0)
			error_msg("he 1st arg must be the config file '*.cub'.");
	}
	if (ac == 3)
	{
		if (ft_memcmp(av[2], "--save\0", 7) == 0)
			bmp = TRUE;
		else
			error_msg("hThe second argument can only be '--save''.");
	}
	if (ac > 3)
		error_msg("There should be no more than two arguments.");
	return (bmp);
}

int				main(int ac, char **av)
{
	t_all		all;
	int			n;

	init_struct(&all);
	validate_argv(ac, av);
	ft_check_len_map(&all, av[1]);
	n = ft_scan_map(&all, av);
	if (n >= 0)
	{
		if (ac == 3)
		{
			if (ft_strncmp("--save", av[2], 7) == 0)
			{
				all.screenshot = 1;
				return (start_mlx(&all));
			}
			else
				return (error_handler(WRONG_SECOND_ARGUMENT));
		}
		else
			return (start_mlx(&all));
	}
}
