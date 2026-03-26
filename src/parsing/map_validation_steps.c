#include "../../includes/cub3d.h"

static void	fill_spaces(t_map *map, char **new_grid, int *row, int *col)
{
	while (*col < map->pos.x)
	{
		new_grid[*row][*col] = ' ';
		(*col)++;
	}
	new_grid[*row][*col] = '\0';
	(*row)++;
}

bool	map_has_only_valid_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (ft_strchr("01 NEWS\n", game->map.grid[y][x]) == NULL)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	map_is_closed(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (ft_strchr("0NEWS", map->grid[y][x]) != NULL)
			{
				if (flood_map(map, x, y) == false)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	normalize_map_grid(t_map *map)
{
	char	**new_grid;
	int		row;
	int		col;

	row = 0;
	new_grid = ft_calloc(map->pos.y + 1, sizeof(char *));
	if (new_grid == NULL)
		return (false);
	while (row < map->pos.y)
	{
		col = 0;
		new_grid[row] = ft_calloc(map->pos.x + 1, sizeof(char));
		if (new_grid[row] == NULL)
			return (free_matrix(new_grid), false);
		new_grid[row] = ft_memcpy(new_grid[row], map->grid[row],
				ft_strlen(map->grid[row]));
		while (new_grid[row][col] && new_grid[row][col] != '\n')
			col++;
		fill_spaces(map, new_grid, &row, &col);
	}
	free_matrix(map->grid);
	new_grid[row] = NULL;
	map->grid = new_grid;
	return (true);
}
