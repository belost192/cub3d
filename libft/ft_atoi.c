/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 20:04:19 by chnikia           #+#    #+#             */
/*   Updated: 2020/06/28 14:34:32 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			result;
	long long	out;
	int			count;

	result = 1;
	out = 0;
	count = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			result = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		out = out * 10 + (*str - 48);
		str++;
		count++;
	}
	if (count > 19)
		return ((result == -1) ? 0 : -1);
	return ((int)out * result);
}
