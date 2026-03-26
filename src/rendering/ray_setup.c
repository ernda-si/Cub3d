#include "../../includes/cub3d.h"

void	init_column_ray(t_game *game, int screen_x)
{
	game->raycast.camera_x = 2 * screen_x / (double)WIDTH - 1;
	game->raycast.ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->raycast.camera_x;
	game->raycast.ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->raycast.camera_x;
	game->raycast.map_x = (int)game->player.pos_x;
	game->raycast.map_y = (int)game->player.pos_y;
}

static void	set_delta_distances(t_game *game)
{
	if (game->raycast.ray_dir_x == 0)
		game->raycast.delta_dist_x = 1e30;
	else
		game->raycast.delta_dist_x = fabs(1 / game->raycast.ray_dir_x);
	if (game->raycast.ray_dir_y == 0)
		game->raycast.delta_dist_y = 1e30;
	else
		game->raycast.delta_dist_y = fabs(1 / game->raycast.ray_dir_y);
}

static void	prepare_x_step(t_game *game)
{
	if (game->raycast.ray_dir_x < 0)
	{
		game->raycast.step_x = -1;
		game->raycast.side_dist_x = (game->player.pos_x - game->raycast.map_x)
			* game->raycast.delta_dist_x;
	}
	else
	{
		game->raycast.step_x = 1;
		game->raycast.side_dist_x = (game->raycast.map_x + 1.0 - game->player.pos_x)
			* game->raycast.delta_dist_x;
	}
}

static void	prepare_y_step(t_game *game)
{
	if (game->raycast.ray_dir_y < 0)
	{
		game->raycast.step_y = -1;
		game->raycast.side_dist_y = (game->player.pos_y - game->raycast.map_y)
			* game->raycast.delta_dist_y;
	}
	else
	{
		game->raycast.step_y = 1;
		game->raycast.side_dist_y = (game->raycast.map_y + 1.0 - game->player.pos_y)
			* game->raycast.delta_dist_y;
	}
}

void	init_dda(t_game *game)
{
	set_delta_distances(game);
	prepare_x_step(game);
	prepare_y_step(game);
}