#include "ft_h.h"

int	create_dict_entry(t_dict **begin, char *str, int nb, int suf)
{
	int		i;
	char	*str2;

	if (suf == 0)
		if (check_exists(*begin, nb) == 0)
			return (0);
	i = 0;
	if (test_line(str, &i) == 0)
		return (0);
	str2 = ft_strdup(str + i);
	if (str2 == NULL)
		return (0);
	str2 = ft_check_space(str2);
	if (str2 == NULL)
		return (0);
	if (ft_list_push_front(begin, nb, suf, str2) == 0)
		return (0);
	return (1);
}
