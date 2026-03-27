/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_entries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:49:25 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:49:26 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	skip_texture_prefix(char **line, char c)
{
	if (c == 'C' || c == 'F')
		(*line) += 1;
	else
		(*line) += 3;
}

static int	find_texture_end(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && (line[i] < 9 || line[i] > 13))
		i++;
	return (i);
}

static bool	valid_texture_tail(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (line[i] && line[i] != '\n')
		return (false);
	return (true);
}

bool	check_texture(char *line, char **img, char c)
{
	int	i;

	skip_texture_prefix(&line, c);
	skip_wspaces(&line);
	i = find_texture_end(line);
	if (line[0] == '\0')
		return (false);
	if ((c != 'C' && c != 'F')
		&& (i < 4 || ft_strstr(line + i - 4, ".xpm") == NULL))
		return (false);
	if (valid_texture_tail(line, i) == false)
		return (false);
	if (*img)
		return (false);
	(*img) = get_word(line, ' ');
	return (true);
}
