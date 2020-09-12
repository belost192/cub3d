/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:16:06 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/24 22:48:05 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_w(const char *str, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (count);
}

static size_t	f_lw(const char *str, char c)
{
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void		*ft_free(char **str, int size)
{
	int i;

	i = 0;
	while (size > i)
		free(str[i++]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**str;

	i = 0;
	count = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (i < ft_count_w(s, c))
	{
		j = 0;
		if (!(str[i] = (char *)malloc(sizeof(char) * (f_lw(&s[count], c) + 1))))
		{
			ft_free(str, count);
			return (NULL);
		}
		while (s[count] == c)
			count++;
		while (s[count] != c && s[count])
			str[i][j++] = s[count++];
		str[i++][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}
