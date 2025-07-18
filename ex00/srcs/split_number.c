#include "ft_h.h"

static void	copy_partial_number(char *nbr, int *i, int *j, char *nbr2)
{
	int	k;

	k = 0;
	while ((*j % 3 != 0) && k < 3)
	{
		nbr2[k++] = nbr[(*i)++];
		(*j)--;
	}
	nbr2[k] = '\0';
}

static int	print_first_chunk(char *nbr, int *i, int *j, t_dict *begin_list)
{
	char	nbr2[4];
	int		nb;

	copy_partial_number(nbr, i, j, nbr2);
	nb = ft_atoi(nbr2);
	send_to_print(nb, begin_list, *i, nbr);
	if (*j == 0)
	{
		ft_putchar('\n');
		return (0);
	}
	if (*j >= 3)
		print_suff(*i, nbr, *j / 3, begin_list);
	return (1);
}

int	first_check(char *nbr, int *i, int *j, t_dict *begin_list)
{
	while (nbr[*i] == '0')
		(*i)++;
	if (*j % 3 != 0)
		return (print_first_chunk(nbr, i, j, begin_list));
	return (1);
}

void	make_three(int i, int j, char *nbr, t_dict *begin_list)
{
	int		nb;
	int		k;
	char	nbr2[4];

	while (j > 0)
	{
		k = 0;
		while (k != 3)
		{
			nbr2[k] = nbr[i];
			i++;
			j--;
			k++;
		}
		nbr2[k] = '\0';
		nb = ft_atoi(nbr2);
		if (nb != 0)
		{
			send_to_print(nb, begin_list, i, nbr);
			if (j >= 3)
				print_suff(i, nbr, j / 3, begin_list);
		}
	}
}

int	check_number(char *nbr, t_dict *begin_list)
{
	int	i;
	int	j;

	i = 0;
	j = check_length(nbr);
	if (j > 3 && check_suff((j - 1) / 3, begin_list) == 0)
		return (0);
	if (ft_atoi(nbr) == 0)
	{
		ft_putstr("zero");
		ft_putchar('\n');
		return (0);
	}
	if (first_check(nbr, &i, &j, begin_list) == 0)
		return (0);
	make_three(i, j, nbr, begin_list);
	ft_putchar('\n');
	return (0);
}
