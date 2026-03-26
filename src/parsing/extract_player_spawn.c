#include "../../includes/cub3d.h"

void	init_player(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (dir == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
}

static bool	set_player_position(t_game *game, int x, int y, char cell)
{
	if (!ft_strchr("NEWS", cell))
		return (true);
	init_player(game, cell);
	if (game->player.pos_x > 0 && game->player.pos_y > 0)
		return (false);
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	return (true);
}

bool	get_player(t_game *game)
{
	int	x;
	int	y;
	char	cell;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			cell = game->map.grid[y][x];
			if (set_player_position(game, x, y, cell) == false)
				return (false);
			x++;
		}
		y++;
	}
	if (game->player.pos_x == -1 || game->player.pos_y == -1)
		print_errors(game, 1, "Player not found in map");
	return (true);
}
