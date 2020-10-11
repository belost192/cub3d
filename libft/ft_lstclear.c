#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*previous;

	if (lst)
	{
		current = *lst;
		while (current)
		{
			previous = current;
			current = current->next;
			(*del)(previous->content);
			free(previous);
			previous = 0;
		}
	}
	*lst = 0;
}