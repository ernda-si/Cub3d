#include "../../includes/struct.h"

void	init_parse(t_parse *p)
{
	p->fd = 0;
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->floor = (t_rgb){-1, -1, -1, -1};
	p->ceiling = (t_rgb){-1, -1, -1, -1};
	p->floor_set = false;
	p->ceiling_set = false;
	p->map = NULL;
	p->map_width = 0;
	p->map_height = 0;
	p->player_x = -1;
	p->player_y = -1;
	p->player_dir = '\0';
	p->found_player = false;
	p->map_started = false;
	p->map_ended = false;
}

void	parse_file(char *file, t_parse *parse)
{
	char	*line;

	init_parse(parse);
	parse->fd = open(file, O_RDONLY);
	if (parse->fd < 0)
		parse_error("Error\nFailed opening file.", NULL);
	while ((line = get_next_line(parse->fd)))
	{
		if(is_empty_line(line, parse))
			handle_empty_line(parse);
		else if (is_texture_line(line))
			parse_texture_line(line, parse);

		free(line);
	}
	close(parse->fd);
	validate_textures_and_colors(parse);
	validate_map(parse);
}
