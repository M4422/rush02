#include "ft_h.h"

char	*addchar(char *str, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = buf[0];
	new[i + 1] = '\0';
	free(str);
	return (new);
}

int	handle_line(char **str, char buf, t_dict **begin)
{
	char	*tmp;

	if (buf != '\n')
	{
		tmp = addchar(*str, &buf);
		if (tmp == NULL)
			return (0);
		*str = tmp;
	}
	else
	{
		if (parse_dict(begin, *str) == 1)
		{
			free(*str);
			*str = malloc(sizeof(char));
			if (*str == NULL)
				return (0);
			(*str)[0] = '\0';
		}
		else if (ft_strlen(*str) != 0)
			return (0);
	}
	return (1);
}

int	gest_buf(int file, t_dict **begin)
{
	int		size;
	char	*str;
	char	buf[1];

	str = malloc(sizeof(char));
	if (str == NULL)
		return (0);
	str[0] = '\0';
	size = read(file, buf, 1);
	while (size != 0)
	{
		if (handle_line(&str, buf[0], begin) == 0)
			return (0);
		size = read(file, buf, 1);
	}
	ft_list_sort(begin);
	return (1);
}

int	ft_file_read(char *filepath, t_dict **begin)
{
	int	file;

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		if (gest_buf(file, begin) == 0)
			return (-1);
		return (1);
	}
	return (0);
}
