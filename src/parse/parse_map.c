#include "../../includes/struct.h"

static void	assign_new_map(t_data *parse, char *line)
{
	char	**new_map;
	int		i;

	i = 0;
	while (parse->map.grid[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		parse_error("Error\nMalloc Failed (map).", parse);
	i = -1;
	while (parse->map.grid[++i])
		new_map[i] = parse->map.grid[i];
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
		parse_error("Error\nMalloc Failed (map).", parse);
	new_map[i + 1] = NULL;
	free(parse->map.grid);
	parse->map.grid = new_map;
}

static void	add_map_line(char *line, t_data *parse)
{
	if (!parse->map.grid)
	{
		parse->map.grid = malloc(sizeof(char *) * 2);
		if (!parse->map.grid)
			parse_error("Error\nMalloc Failed (map).", parse);
		parse->map.grid[0] = ft_strdup(line);
		if (!parse->map.grid[0])
			parse_error("Error\nMalloc Failed (map).", parse);
		parse->map.grid[1] = NULL;
		return ;
	}
	assign_new_map(parse, line);
}

void	parse_map_line(char *line, t_data *parse)
{
	if (parse->map_ended)
		parse_error("Error\nInvalid Map.", parse);
	parse->map_started = true;
	add_map_line(line, parse);
}
