/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:14:24 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/24 19:13:47 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		sym;
	unsigned char		*p_dst;

	sym = (unsigned char)c;
	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	while (n--)
	{
		*p_dst++ = *p_src++;
		if (*(p_dst - 1) == sym)
			return (p_dst);
	}
	return (NULL);
}
