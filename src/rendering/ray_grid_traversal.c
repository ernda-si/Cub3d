#include "../../includes/cub3d.h"

static void	step_ray(t_game *game, int *hit_side)
{
	if (game->raycast.side_dist_x < game->raycast.side_dist_y)
	{
		game->raycast.side_dist_x += game->raycast.delta_dist_x;
		game->raycast.map_x += game->raycast.step_x;
		*hit_side = 0;
	}
	else
	{
		game->raycast.side_dist_y += game->raycast.delta_dist_y;
		game->raycast.map_y += game->raycast.step_y;
		*hit_side = 1;
	}
}

static int	check_ray_hit(t_game *game)
{
	char	cell;

	cell = game->map.grid[game->raycast.map_y][game->raycast.map_x];
	if (cell == '1')
		return (1);
	return (0);
}

int	find_wall_hit(t_game *game)
{
	int	has_hit;
	int	hit_side;

	has_hit = 0;
	hit_side = 0;
	while (has_hit == 0)
	{
		step_ray(game, &hit_side);
		has_hit = check_ray_hit(game);
	}
	return (hit_side);
}