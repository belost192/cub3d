/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:02:10 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 13:43:28 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_clean_line(char *list, char **line, int size)
{
	const size_t	len = ft_strlen(list);
	size_t			i;
	char			*tmp;

	i = 0;
	while (list[i])
	{
		if (list[i] == '\n')
			break ;
		i++;
	}
	if (i < len)
	{
		*line = ft_substr(list, 0, i);
		tmp = ft_substr(list, i + 1, len);
		free(list);
		list = tmp;
	}
	else if (size == 0)
	{
		*line = list;
		list = NULL;
	}
	return (list);
}

static char	*ft_add_to_list(char *buf, char *list)
{
	char	*tmp;

	if (list)
	{
		tmp = ft_strjoin(list, buf);
		free(list);
		list = tmp;
	}
	else
		list = ft_strdup(buf);
	return (list);
}

int			get_next_line(int text, char **line)
{
	static char	*list[10000];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;

	if (text < 0 || line == NULL || read(text, buf, 0) != 0)
		return (-1);
	while ((size = read(text, buf, BUFFER_SIZE)))
	{
		if (size == -1)
			return (-1);
		buf[size] = '\0';
		if (!(list[text] = ft_add_to_list(buf, list[text])))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (size <= 0 && !list[text])
	{
		*line = ft_strdup("");
		return (0);
	}
	list[text] = ft_clean_line(list[text], line, size);
	if (!list[text])
		return (0);
	return (1);
}
