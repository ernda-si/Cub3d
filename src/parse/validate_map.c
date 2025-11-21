#include "../../includes/struct.h"

static size_t	get_map_height(char **map)
{
	size_t	h;

	if (!map)
		return (0);
	h = 0;
	while (map[h])
		h++;
	return (h);
}

size_t	get_map_max_width(char **map)
{
	size_t	max;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!map)
		return (0);
	max = 0;
	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]);
		while (j > 0 && (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'))
			j--;
		len = j;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static void	check_closed_cell(t_data *p, size_t y, size_t x)
{
	char	c;

	c = p->map.grid[y][x];
	if (c != '0' && !ft_strchr("NEWS", c))
		return ;
	if (x == 0 || y == 0 || p->map.grid[y + 1] == NULL || p->map.grid[y][x + 1] == '\0')
		parse_error("Error\nMap open (edge).", p);
	if (x >= ft_strlen(p->map.grid[y + 1]) || p->map.grid[y + 1][x] == ' ')
		parse_error("Error\nMap leaks downwards.", p);
	if (x >= ft_strlen(p->map.grid[y - 1]) || p->map.grid[y - 1][x] == ' ')
		parse_error("Error\nMap leaks upwards.", p);
	if (p->map.grid[y][x - 1] == ' ' || ft_isspace(p->map.grid[y][x - 1]))
		parse_error("Error\nMap leaks left", p);
	if (p->map.grid[y][x + 1] == ' ' || ft_isspace(p->map.grid[y][x + 1]))
		parse_error("Error\nMap leaks right", p);
}

void	check_closed_map(t_data *parse)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (parse->map.grid[y])
	{
		x = 0;
		while (parse->map.grid[y][x])
		{
			check_closed_cell(parse, y, x);
			x++;
		}
		y++;
	}
	parse->map.height = get_map_height(parse->map.grid);
	parse->map.width = get_map_max_width(parse->map.grid);
}
