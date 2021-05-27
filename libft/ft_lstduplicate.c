#include "libft.h"

t_list	*ft_lstduplicate(t_list *list)
{
	t_list	*new_lst;

	if (!list)
		return NULL;
	new_lst = ft_lstnew(list->content);
	list = list->next;
	while (list)
	{
		ft_lstadd_back(&new_lst, list);
		list = list->next;
	}
	return (new_lst);
}
