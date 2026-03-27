/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:03:25 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:26 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	running_loops(t_game *game)
{
	action(game);
	draw_frame(game);
}

int	main_loop(t_game *game)
{
	running_loops(game);
	return (0);
}
