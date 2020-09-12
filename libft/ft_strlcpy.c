/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 11:50:27 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/27 19:49:56 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	const char	*str1;
	size_t		n;

	str1 = src;
	n = size;
	if (!src || !dest)
		return (0);
	if (n)
	{
		while (--n)
		{
			if (*src)
				*dest++ = *src++;
		}
	}
	if (n == 0)
	{
		if (size)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - str1 - 1);
}
