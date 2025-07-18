#include "ft_h.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_dict	*ft_create_elem(int n, int suf, char *literal)
{
	t_dict	*created;

	created = NULL;
	created = malloc(sizeof(t_dict));
	if (created == NULL)
		return (NULL);
	if (created)
	{
		created->nb = n;
		created->suf = suf;
		created->literal = malloc(sizeof(char) * (strlen(literal) + 1));
		if (created->literal == NULL)
			return (NULL);
		created->literal = literal;
		created->next = NULL;
	}
	return (created);
}
