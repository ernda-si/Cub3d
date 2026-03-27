/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_config_validation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:49:29 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:56:49 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	parse_color_line(char *line, t_game *game, bool is_ceiling)
{
	char	**dst;

	if (is_ceiling)
		dst = &game->assets.ceiling.nums;
	else
		dst = &game->assets.floor.nums;
	if (check_texture(line, dst, line[0]) == false)
	{
		free(line);
		if (is_ceiling)
			print_errors(game, 1, "Invalid ceiling color");
		print_errors(game, 1, "Invalid floor color");
	}
}

static void	check_walls(char *line, t_game *game)
{
	char	**letters;
	int		i;

	i = -1;
	letters = letters_init();
	while (++i < 4)
	{
		if (ft_strncmp(line, letters[i], 3) == 0
			&& !game->assets.textures[i].filename)
		{
			if (check_texture(line,
					&game->assets.textures[i].filename, 'W') == false)
			{
				free(line);
				print_errors(game, 1, "Invalid texture line");
			}
			return ;
		}
	}
	free(line);
	print_errors(game, 1,
		"Invalid input: use only NO, SO, WE, EA, C and F");
}

static bool	check_line(char *line, t_game *game)
{
	skip_wspaces(&line);
	if (line[0] == '\0' || line[0] == '\n')
		return (true);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color_line(line, game, true), true);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color_line(line, game, false), true);
	check_walls(line, game);
	return (true);
}

static bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_strchr(" \t\v\f\r", line[i]))
		i++;
	if (line[i] == '\n')
		return (false);
	while (line[i])
	{
		if (ft_strchr(" 10NEWS\n", line[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

char	*get_textures(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	if (line == NULL)
		print_errors(game, 0, "Empty file");
	while (line != NULL)
	{
		if (is_map(line) == true)
			return (line);
		game->map.breakp++;
		check_line(line, game);
		free(line);
		line = get_next_line(game->fd);
	}
	return (NULL);
}
