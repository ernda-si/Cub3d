#include "../../includes/struct.h"

bool	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (true);
	i = 0;
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	handle_empty_line(t_data *parse)
{
	if (parse->map_started)
		parse->map_ended = true;
}

bool	is_texture_line(char *line)
{
	if (!line)
		return (false);
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (true);
	if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (true);
	if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (true);
	if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (true);
	if (!ft_strncmp(line, "F", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (true);
	if (!ft_strncmp(line, "C", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (true);
	return (false);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\r' || c == '\v' || c == '\f');
}

int	check_digits(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (0);
	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
			return (0);
	}
	return (1);
}
