/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:15:19 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/24 19:15:20 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str1;
	unsigned char sym;

	str1 = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*str1 == sym)
			return (str1);
		str1++;
	}
	return (NULL);
}
