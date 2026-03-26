#include "../../includes/cub3d.h"

double	compute_wall_dist(t_game *game)
{
	if (game->raycast.hit_side == 0)
		return (game->raycast.side_dist_x - game->raycast.delta_dist_x);
	return (game->raycast.side_dist_y - game->raycast.delta_dist_y);
}

void	compute_wall_slice(t_game *game, double wall_dist,
		int *wall_start_y, int *wall_end_y)
{
	int	look_offset;

	look_offset = game->player.look;
	if (wall_dist <= 0.000001)
		wall_dist = 0.000001;
	game->raycast.wall_height = (int)(HEIGHT / wall_dist);
	(*wall_start_y) = HEIGHT / 2 - game->raycast.wall_height / 2 + look_offset;
	if ((*wall_start_y) < 0)
		(*wall_start_y) = 0;
	(*wall_end_y) = HEIGHT / 2 + game->raycast.wall_height / 2 + look_offset;
	if ((*wall_end_y) < 0)
		(*wall_end_y) = 0;
}