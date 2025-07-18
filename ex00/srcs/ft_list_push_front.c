#include "ft_h.h"

int	ft_list_push_front(t_dict **liste, int n, int suf, char *lit)
{
	t_dict	*push;

	if (liste)
	{
		push = ft_create_elem(n, suf, lit);
		if (push == NULL)
			return (0);
		push->next = *liste;
		*liste = push;
	}
	else
	{
		*liste = ft_create_elem(n, suf, lit);
		if (*liste == NULL)
			return (0);
	}
	return (1);
}
