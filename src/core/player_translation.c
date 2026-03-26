#include "../../includes/cub3d.h"

static void	move_player(t_game *game, double speed, double axis_x,
		double axis_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + axis_x * speed;
	new_y = game->player.pos_y + axis_y * speed;
	if (hit_box(game, new_x, game->player.pos_y, 1) == true)
		game->player.pos_x = new_x;
	if (hit_box(game, game->player.pos_x, new_y, 1) == true)
		game->player.pos_y = new_y;
}

void	move_forward(t_game *game, double speed)
{
	move_player(game, speed, game->player.dir_x, game->player.dir_y);
}

void	move_back(t_game *game, double speed)
{
	move_player(game, speed, -game->player.dir_x, -game->player.dir_y);
}

void	move_left(t_game *game, double speed)
{
	move_player(game, speed, -game->player.plane_x, -game->player.plane_y);
}

void	move_right(t_game *game, double speed)
{
	move_player(game, speed, game->player.plane_x, game->player.plane_y);
}
