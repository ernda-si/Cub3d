#include "../../includes/cub3d.h"

int	action(t_game *game)
{
	if (game->movement_state[move_cmd_forward] == 1)
		move_forward(game, game->player.speed);
	else if (game->movement_state[move_cmd_backward] == 1)
		move_back(game, game->player.speed);
	if (game->movement_state[move_cmd_strafe_left] == 1)
		move_left(game, game->player.speed);
	if (game->movement_state[move_cmd_strafe_right] == 1)
		move_right(game, game->player.speed);
	if (game->movement_state[move_cmd_turn_right] == 1)
		look_right(game);
	if (game->movement_state[move_cmd_turn_left] == 1)
		look_left(game);
	return (0);
}
