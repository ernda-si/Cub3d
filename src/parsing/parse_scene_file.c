/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:49:20 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:49:21 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	parse(t_game *game, char *filename)
{
	char	*line;

	init_vars(game);
	game->fd = open(filename, O_RDONLY);
	if (game->fd == -1)
		print_errors(game, 0, "Failed to open map file");
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
		print_errors(game, 0, "File must end with .cub");
	line = get_textures(game);
	if (!game->assets.ceiling.nums || !game->assets.floor.nums
		|| !game->assets.textures[NTEX].filename
		|| !game->assets.textures[ETEX].filename
		|| !game->assets.textures[WTEX].filename
		|| !game->assets.textures[STEX].filename)
	{
		free(line);
		print_errors(game, 1, "Missing texture or color");
	}
	parse_map(game, filename, line);
	parse_colors(game);
	close(game->fd);
	return (true);
}
