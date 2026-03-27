/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:49:34 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:49:35 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	map_has_only_valid_chars(t_game *game);
bool	map_is_closed(t_map *map);
bool	normalize_map_grid(t_map *map);

void	parse_map(t_game *game, char *filename, char *line)
{
	get_map(game, filename, line);
	if (map_has_only_valid_chars(game) == false)
		print_errors(game, 1, "Invalid character in map");
	if (get_player(game) == false)
		print_errors(game, 1, "Map must contain exactly one player");
	if (map_is_closed(&game->map) == false)
		print_errors(game, 1, "Invalid map (not closed)");
	if (normalize_map_grid(&game->map) == false)
		print_errors(game, 1, "Failed to normalize map grid");
}
