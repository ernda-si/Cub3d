/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:24:57 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:29:18 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_TYPES_H
# define GAME_TYPES_H

enum				e_move
{
	move_cmd_forward,
	move_cmd_backward,
	move_cmd_strafe_left,
	move_cmd_strafe_right,
	move_cmd_turn_right,
	move_cmd_turn_left
};

typedef struct s_view_flags
{
	bool				is_turning_right;
	bool				is_turning_left;
}					t_view_flags;

typedef struct s_game
{
	int					fd;
	void				*mlx;
	void				*win;

	t_map				map;
	t_assets			assets;
	t_player			player;
	t_ray				raycast;
	t_view_flags		view_flags;

	t_img				bg_img;

	double				wall_distance;
	int					movement_state[6];
}					t_game;

#endif