/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:03:40 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:41 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		closex(game);
	if (keycode == W)
		game->movement_state[move_cmd_forward] = 1;
	if (keycode == S)
		game->movement_state[move_cmd_backward] = 1;
	if (keycode == A)
		game->movement_state[move_cmd_strafe_left] = 1;
	if (keycode == D)
		game->movement_state[move_cmd_strafe_right] = 1;
	if (keycode == ARROW_RIGHT)
	{
		game->view_flags.is_turning_right = true;
		game->movement_state[move_cmd_turn_right] = 1;
	}
	if (keycode == ARROW_LEFT)
	{
		game->view_flags.is_turning_left = true;
		game->movement_state[move_cmd_turn_left] = 1;
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->movement_state[move_cmd_forward] = 0;
	if (keycode == S)
		game->movement_state[move_cmd_backward] = 0;
	if (keycode == A)
		game->movement_state[move_cmd_strafe_left] = 0;
	if (keycode == D)
		game->movement_state[move_cmd_strafe_right] = 0;
	if (keycode == ARROW_RIGHT)
	{
		game->view_flags.is_turning_right = false;
		game->movement_state[move_cmd_turn_right] = 0;
	}
	if (keycode == ARROW_LEFT)
	{
		game->view_flags.is_turning_left = false;
		game->movement_state[move_cmd_turn_left] = 0;
	}
	return (0);
}
