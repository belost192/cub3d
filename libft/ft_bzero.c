/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:06:52 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 14:37:50 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Overwrites string bytes to zero bytes of length 'n'.
*/

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*ptr;

	if (!str)
		return ;
	ptr = (unsigned char *)str;
	while (len--)
		*ptr++ = '\0';
}
