#include "../../includes/cub3d.h"

static void	find_map(t_game *game, char *line)
{
	int	i;
	int	seen_map_char;

	seen_map_char = 0;
	i = -1;
	while (line[++i])
	{
		if (ft_strchr("10NEWS", line[i]))
			seen_map_char = 1;
		if (seen_map_char == 0 && game->map.exists == false
			&& ft_isprint(line[i]) && (line[i] != ' '
				|| (line[i] < 9 || line[i] > 13)))
		{
			free(line);
			print_errors(game, 1, "Invalid character before map");
		}
	}
	if (seen_map_char == 0 && game->map.exists == false)
		game->map.breakp++;
	else
		game->map.exists = true;
}

static void	update_map_size(t_game *game, char *line)
{
	size_t	len;

	if (!game->map.exists)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len > game->map.pos.x)
		game->map.pos.x = len;
	game->map.pos.y++;
}

static bool	get_grid(t_game *game, char *filename)
{
	int		idx;
	char	*line;

	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		print_errors(game, 1, "Failed to open file");
	idx = 0;
	while (idx++ < game->map.breakp)
	{
		line = get_next_line(game->fd);
		free(line);
	}
	idx = 0;
	while (1)
	{
		game->map.grid[idx] = get_next_line(game->fd);
		if (game->map.grid[idx++] == NULL)
			return (close(game->fd), true);
	}
}

bool	get_map(t_game *game, char *filename, char *line)
{
	if (line == NULL)
		print_errors(game, 1, "No map found");
	while (line != NULL)
	{
		find_map(game, line);
		update_map_size(game, line);
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.grid = ft_calloc(game->map.pos.y + 1, sizeof(char *));
	if (game->map.grid == NULL)
		print_errors(game, 1, "Failed to allocate memory for map");
	close(game->fd);
	get_grid(game, filename);
	return (true);
}
