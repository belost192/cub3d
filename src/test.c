/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:09:22 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 19:22:09 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_mms_20200219/mlx.h"
#include "../libft/libft.h"
#include "fcntl.h"

char	**make_map(t_list **head, int size)
{
	char	**map = ft_calloc(size + 1, sizeof(char *));
	int i = -1;
	t_list *tmp = *head;

	while (tmp)
	{
		map(++i) = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (*map);
}

char	**ft_read_map(void)
{
	int size;
	char *line = NULL;
	t_list *head = NULL;
	int fd = open("../map/map.cub", O_RDONLY);

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head)
return (make_map(&head, ft_lstsize(head)));
}
