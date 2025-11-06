#include "../../includes/struct.h"

bool	is_empty_line(char *line, t_parse *parse)
{
	int	i;

	if (!line)
		return (true);
	i = 0;
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	handle_empty_line(t_parse *parse)
{
	if (parse->map_started)
		parse->map_ended = true;
}

bool	is_texture_line(char *line)
{
	if (!line)
		return (false);
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3) \
			|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
			return (true);
	return (false);
}

static void	assign_color(t_rgb *color, char **rgb, t_parse *parse, char **split)
{

	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || \
		color->b < 0 || color->b > 255)
	{
		free_split(rgb);
		free_split(split);
		parse_error("Error\nRGB values must be between 0 and 255.", parse);
	}
	color->hex = (color->r << 16) | (color->g << 8) | color->b;
}

static int	check_digits(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (0);
	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
			return (0);
	}
	return (1);
}

static t_rgb	parse_rgb(char *str, t_parse *parse, char **split)
{
	t_rgb	color;
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_split(rgb);
		free_split(split);
		parse_error("Error\nInvalid RGB format.", parse);
	}
	i = 0;
	while (i < 3)
	{
		if (!check_digits(rgb[i++]))
		{
			free_split(rgb);
			free_split(split);
			parse_error("Error\nRGB Values must be numeric.", parse);
		}
	}
	assign_color(&color, rgb, parse, split);
	free_split(rgb);
	return (color);
}

static void	assign_texture(char *tmp, char **split, t_parse *parse)
{
	if (!ft_strncmp(split[0], "NO", 3))
	{
		if (parse->no)
			return (free_split(split), parse_error("Error\nDuplicated Texture: NO.", parse));
		parse->no = tmp;
	}
	else if (!ft_strncmp(split[0], "SO", 3))
	{
		if (parse->so)
			return (free_split(split), parse_error("Error\nDuplicated Texture: SO.", parse));
		parse->so = tmp;
	}
	else if (!ft_strncmp(split[0], "WE", 3))
	{
		if (parse->we)
			return (free_split(split), parse_error("Error\nDuplicated Texture: WE.", parse));
		parse->we = tmp;
	}
	else if (!ft_strncmp(split[0], "EA", 3))
	{
		if (parse->ea)
			return (free_split(split), parse_error("Error\nDuplicated Texture: EA.", parse));
		parse->ea = tmp;
	}
}

static bool	is_dup_rgb(t_parse *parse, char **split)
{
	if (!ft_strncmp(split[0], "F", 2))
	{
		if (parse->floor.hex >= 0)
		{
			free_split(split);
			parse_error("Error\nDuplicated Texture: F.", parse);
			return (true);
		}
	}
	if (!ft_strncmp(split[0], "C", 2))
	{
		if (parse->ceiling.hex >= 0)
		{
			free_split(split);
			parse_error("Error\nDuplicated Texture: C.", parse);
			return (true);
		}
	}
	return (false);
}

void	parse_texture_line(char *line, t_parse *parse)
{
	char	**split;
	char	*tmp;
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		parse_error("Error\nMemory allocation failed.", parse);
	split = ft_split(trimmed, ' ');
	free(trimmed);
	if (!split || !split[0] || !split[1])
		return (free_split(split), parse_error("Error\nParse Failed.", parse));
	if (!ft_strncmp(split[0], "NO", 3) || !ft_strncmp(split[0], "SO", 3) || \
			!ft_strncmp(split[0], "WE", 3) || !ft_strncmp(split[0], "EA", 3))
	{
		tmp = ft_strdup(split[1]);
		if (!tmp)
			return (free_split(split), parse_error("Error\nM. allocation failed.", parse));
		assign_texture(tmp, split, parse);
	}
	else if (!ft_strncmp(split[0], "F", 2) && !is_dup_rgb(parse, split))
		parse->floor = parse_rgb(split[1], parse, split);
	else if (!ft_strncmp(split[0], "C", 2) && !is_dup_rgb(parse, split))
		parse->ceiling = parse_rgb(split[1], parse, split);
	free_split(split);
}
