#include "../../includes/struct.h"

void	init_data(t_data *d)
{
	d->fd = 0;
	d->no = NULL;
	d->so = NULL;
	d->we = NULL;
	d->ea = NULL;
	d->floor = (t_rgb){-1, -1, -1, -1};
	d->ceiling = (t_rgb){-1, -1, -1, -1};
	d->floor_set = false;
	d->ceiling_set = false;
	d->map.grid = NULL;
	d->map.width = 0;
	d->map.height = 0;
	d->player.x = -1;
	d->player.y = -1;
	d->player.dir = '\0';
	d->file_line = NULL;
	d->map_started = false;
	d->map_ended = false;
}

void	parse_file(char *file, t_data *parse)
{
	init_data(parse);
	parse->fd = open(file, O_RDONLY);
	if (parse->fd < 0)
		parse_error("Error\nFailed opening file.", NULL);
	while ((parse->file_line = get_next_line(parse->fd)))
	{
		if(is_empty_line(parse->file_line))
			handle_empty_line(parse);
		else if (is_texture_line(parse->file_line))
			parse_texture_line(parse->file_line, parse);
		else
			parse_map_line(parse->file_line, parse);
		free(parse->file_line);
	}
	close(parse->fd);
	validate_textures_and_colors(parse);
	//print_map(parse);
	validate_map(parse);
	//printf("passed");
}

// Final state after parse_file():
//   - All texture paths (NO, SO, WE, EA) are loaded and stored in d->no / d->so etc..
//   - Floor and ceiling RGB values are parsed and validated.
//   - The raw map is fully loaded into parse->map.grid
//   - Map dimensions (width/height) are computed
//   - Player initial position (x, y) and direction (N/S/E/W) are detected and stored
//   - The map is validated: allowed chars, single player, and closed layout.
//   - No memory leaks remain from intermediate allocations (GNL lines, splits, fd, etc)
//   - At this point, 'parse' contains a complete, validated game configuration
//     ready for initialization of the game engine