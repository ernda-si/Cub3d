/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:49:16 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:49:17 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	skip_comma(t_color *colors, int *i, bool last_check)
{
	if (colors->nums[*i] && colors->nums[*i] == ',')
		return (false);
	while (colors->nums[*i] && colors->nums[*i] != ',')
		(*i)++;
	if (colors->nums[*i] && colors->nums[*i] == ',' && last_check == false)
		(*i)++;
	if (colors->nums[*i] == '\0' && last_check == false)
		return (false);
	if (colors->nums[*i] != '\0' && last_check == true)
		return (false);
	return (true);
}

bool	get_colors(t_color *colors)
{
	int		i;
	char	*red;
	char	*blue;
	char	*green;

	i = 0;
	red = get_word(colors->nums, ',');
	if (skip_comma(colors, &i, false) == false)
		return (free(red), false);
	green = get_word(colors->nums + i, ',');
	if (skip_comma(colors, &i, false) == false)
		return (free(red), free(green), false);
	blue = get_word(colors->nums + i, ',');
	if (skip_comma(colors, &i, true) == false)
		return (free(red), free(green), free(blue), false);
	colors->red = ft_atol(red);
	colors->green = ft_atol(green);
	colors->blue = ft_atol(blue);
	free(red);
	free(blue);
	free(green);
	return (true);
}

bool	check_colors(t_color colors)
{
	int	i;

	i = 0;
	while (colors.nums[i])
	{
		if (!ft_isdigit(colors.nums[i]) && colors.nums[i] != ',')
			return (false);
		i++;
	}
	if (colors.red < 0 || colors.red > 255)
		return (false);
	if (colors.green < 0 || colors.green > 255)
		return (false);
	if (colors.blue < 0 || colors.blue > 255)
		return (false);
	return (true);
}

void	parse_colors(t_game *game)
{
	if (get_colors(&game->assets.ceiling) == false
		|| get_colors(&game->assets.floor) == false)
		print_errors(game, 1, "Invalid color format");
	if (check_colors(game->assets.ceiling) == false
		|| check_colors(game->assets.floor) == false)
		print_errors(game, 1, "Color value out of range (0-255)");
	game->assets.ceiling.hexa = color_hexa(game, game->assets.ceiling);
	game->assets.floor.hexa = color_hexa(game, game->assets.floor);
}
