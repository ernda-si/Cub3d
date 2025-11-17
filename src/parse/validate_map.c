#include "../../includes/struct.h"

static void	check_closed_cell(t_parse *p, size_t y, size_t x)
{
	char	c;

	c = p->map[y][x];
	if (c != '0' && !ft_strchr("NEWS", c))
		return ;
	if (x == 0 || y == 0 || p->map[y + 1] == NULL || p->map[y][x + 1] == '\0')
		parse_error("Error\nMap open (edge).", p);
	if (x >= ft_strlen(p->map[y + 1]) || p->map[y + 1][x] == ' ')
		parse_error("Error\nMap leaks downwards.", p);
	if (x >= ft_strlen(p->map[y - 1]) || p->map[y - 1][x] == ' ')
		parse_error("Error\nMap leaks upwards.", p);
	if (p->map[y][x - 1] == ' ')
		parse_error("Error\nMap leaks left", p);
	if (p->map[y][x + 1] == ' ')
		parse_error("Error\nMap leaks right", p);
}

void	check_closed_map(t_parse *parse)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (parse->map[y])
	{
		x = 0;
		while (parse->map[y][x])
		{
			check_closed_cell(parse, y, x);
			x++;
		}
		y++;
	}
}
