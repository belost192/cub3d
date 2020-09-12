/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:10:07 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/26 13:37:53 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*p_s1;
	char	*p_s2;

	p_s1 = (char *)s1;
	p_s2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strlcpy(new, p_s1, (ft_strlen(s1) + 1));
	ft_strlcat(new, p_s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (new);
}
