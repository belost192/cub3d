/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:06:52 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 14:37:50 by chnikia          ###   ########.fr       */
=======
<<<<<<< HEAD:libft/ft_bzero.c
/*   ft_bzero.c                                         :+:      :+:    :+:   */
=======
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
>>>>>>> cub2d:libft/ft_lstnew.c
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:libft/ft_bzero.c
/*   Created: 2020/05/18 22:09:46 by chnikia           #+#    #+#             */
/*   Updated: 2020/05/26 13:33:49 by chnikia          ###   ########.fr       */
=======
/*   Created: 2020/08/05 14:06:52 by chnikia           #+#    #+#             */
/*   Updated: 2020/08/05 14:37:50 by chnikia          ###   ########.fr       */
>>>>>>> cub2d:libft/ft_lstnew.c
>>>>>>> cub2d
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
=======
<<<<<<< HEAD:libft/ft_bzero.c
void	ft_bzero(void *str, size_t len)
{
	unsigned char	*str1;

	str1 = (unsigned char *)str;
	while (len--)
		*str1++ = '\0';
=======
>>>>>>> cub2d
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
<<<<<<< HEAD
=======
>>>>>>> cub2d:libft/ft_lstnew.c
>>>>>>> cub2d
}
