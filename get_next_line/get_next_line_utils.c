#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_GNL(char *line, char *buff, size_t	line_len, size_t buff_len)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = 0;
	j = 0;
	result = malloc(line_len + buff_len + 1);
	if (!result)
		return (free(line), NULL);
	while (i < line_len)
	{
		result[i] = line[i];
		i++;
	}
	while (j < buff_len)
		result[i++] = buff[j++];
	result[i] = '\0';
	return (free(line), result);
}

int	cut_buff(char *buffer)
{
	long	i;
	long	j;

	j = -1;
	i = 0;
	while (buffer[i])
	{
		if (j != -1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n' && j == -1)
			j++;
		buffer[i++] = '\0';
	}
	return (j != -1);
}
