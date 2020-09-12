/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:22:02 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/24 19:39:54 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mas, int sym, size_t n)
{
	unsigned char	*str;
	unsigned char	c;

	str = (unsigned char *)mas;
	c = (unsigned char)sym;
	while (n--)
		*(str++) = c;
	return (mas);
}
