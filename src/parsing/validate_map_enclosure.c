/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_enclosure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:49:39 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 18:52:57 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	change_grid(t_map *map, int x, int y)
{
	if (map->grid[y][x] == '0')
		map->grid[y][x] = 'o';
	else if (map->grid[y][x] == 'N')
		map->grid[y][x] = 'o';
	else if (map->grid[y][x] == 'E')
		map->grid[y][x] = 'o';
	else if (map->grid[y][x] == 'W')
		map->grid[y][x] = 'o';
	else if (map->grid[y][x] == 'S')
		map->grid[y][x] = 'o';
}

bool	flood_map(t_map *map, int x, int y)
{
	if (y >= 0 && y < map->pos.y && x >= 0
		&& x < (int)ft_strlen(map->grid[y])
		&& map->grid[y][x] &&
			(map->grid[y][x] == '1' || map->grid[y][x] == 'o'))
		return (true);
	if (y < 0 || y >= map->pos.y || x < 0
		|| x >= (int)ft_strlen(map->grid[y]) || map->grid[y][x] == '\0'
		|| ft_strchr("10oNEWSnews", map->grid[y][x]) == NULL)
		return (false);
	change_grid(map, x, y);
	if (flood_map(map, x - 1, y) == false)
		return (false);
	if (flood_map(map, x + 1, y) == false)
		return (false);
	if (flood_map(map, x, y - 1) == false)
		return (false);
	if (flood_map(map, x, y + 1) == false)
		return (false);
	return (true);
}
