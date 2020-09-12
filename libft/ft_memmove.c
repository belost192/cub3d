/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:48:36 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/24 19:29:48 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *p_src;
	unsigned char *p_dst;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dest;
	if (!p_dst && !p_src)
		return (dest);
	if (p_dst < p_src)
		while (n--)
			*p_dst++ = *p_src++;
	else
		while (n--)
			p_dst[n] = p_src[n];
	return (dest);
}
