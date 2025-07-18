#include "ft_h.h"

void	ft_list_clear(t_dict **begin_with)
{
	t_dict	*ptr;
	t_dict	*liste;

	liste = *begin_with;
	if (liste)
	{
		while (liste)
		{
			ptr = liste->next;
			free(liste->literal);
			free(liste);
			liste = ptr;
		}
	}
}
