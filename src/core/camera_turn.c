#include "../../includes/cub3d.h"

static void	apply_view_rotation(t_game *game, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotation_angle)
		- game->player.dir_y * sin(rotation_angle);
	game->player.dir_y = old_dir_x * sin(rotation_angle)
		+ game->player.dir_y * cos(rotation_angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotation_angle)
		- game->player.plane_y * sin(rotation_angle);
	game->player.plane_y = old_plane_x * sin(rotation_angle)
		+ game->player.plane_y * cos(rotation_angle);
}

static void	rotate_view(t_game *game, int arrow_step, bool keyboard_turn)
{
	double	angle;
	int		step;

	step = arrow_step;
	angle = ARROW_ROT_SPEED;
	if (keyboard_turn == false)
		angle = ROT_SPEED;
	apply_view_rotation(game, step * angle);
}

void	look_right(t_game *game)
{
	rotate_view(game, 1, game->view_flags.is_turning_right);
}

void	look_left(t_game *game)
{
	rotate_view(game, -1, game->view_flags.is_turning_left);
}
