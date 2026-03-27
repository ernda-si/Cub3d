/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:03:50 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:51 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**letters_init(void)
{
	static char	*letters[4];

	letters[NTEX] = "NO ";
	letters[ETEX] = "EA ";
	letters[WTEX] = "WE ";
	letters[STEX] = "SO ";
	return (letters);
}

void	init_vars(t_game *game)
{
	game->player.pos_x = -1;
	game->player.pos_y = -1;
	game->player.look = 0;
}
