#include "../includes/struct.h"

void	validate_args(int ac, char **av)
{
	size_t	len;
	int		fd;

	if (ac != 2)
		parse_error("Error\nInvalid number of arguments.", NULL);
	if (!av[1])
		parse_error("Error\nMissing map file.", NULL);
	len = ft_strlen(av[1]);
	if (len <= 4 || ft_strncmp(av[1] + len - 4, ".cub", 4) != 0)
		parse_error("Error\nInvalid map format (map.cub).", NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		parse_error("Error\nCan not open map file.", NULL);
	close(fd);
	return ;
}

void	validate_textures_and_colors(t_data *parse)
{
	if (!parse->no)
		parse_error("Error\nMissing texture: NO.", parse);
	if (!parse->so)
		parse_error("Error\nMissing texture: SO.", parse);
	if (!parse->we)
		parse_error("Error\nMissing texture: WE.", parse);
	if (!parse->ea)
		parse_error("Error\nMissing texture: EA.", parse);
	if (parse->floor.hex < 0)
		parse_error("Error\nMissing floor color (F).", parse);
	if (parse->ceiling.hex < 0)
		parse_error("Error\nMissing ceiling color (C).", parse);
}

static void	check_allowed_chars(t_data *parse)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (parse->map.grid[y])
	{
		x = 0;
		while (parse->map.grid[y][x])
		{
			c = parse->map.grid[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && \
				c != 'E' && c != 'W' && c != ' ' && c != '\n')
				parse_error("Error\nInvalid character in map.", parse);
			x++;
		}
		y++;
	}
}

static void	check_single_player(t_data *parse)
{
	int	y;
	int	x;
	int	player_count;

	player_count = 0;
	y = 0;
	while (parse->map.grid[y])
	{
		x = 0;
		while (parse->map.grid[y][x])
		{
			if (ft_strchr("NSEW", parse->map.grid[y][x]))
			{
				player_count++;
				parse->player.dir = parse->map.grid[y][x];
				parse->player.y = y;
				parse->player.x = x;
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		parse_error("Error\nThere must be exactly one player start.", parse);
}

void	validate_map(t_data *parse)
{
	check_allowed_chars(parse);
	check_single_player(parse);
	check_closed_map(parse);
}
