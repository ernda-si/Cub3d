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

void	validate_textures_and_colors(t_parse *parse)
{
	if (!parse->no || !parse->so || !parse->we || !parse->ea)
		parse_error("Error\nMissing one or more textures.", parse);
	if (parse->floor.hex < 0 || parse->ceiling.hex < 0)
		parse_error("Error\nMissing floor or ceiling color.", parse);
}
