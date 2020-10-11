#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *array;

	if (!(array = malloc(sizeof(t_list))))
		return (NULL);
	array->content = content;
	array->next = NULL;
	return (array);
}