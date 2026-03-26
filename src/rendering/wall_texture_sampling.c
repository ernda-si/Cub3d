#include "../../includes/cub3d.h"

void	choose_wall_texture(t_game *game, t_img *sprite, t_point *text,
		double wall_x)
{
	if (game->raycast.hit_side == 0 && game->raycast.ray_dir_x < 0)
		(*sprite) = game->assets.textures[WTEX];
	else if (game->raycast.hit_side == 0 && game->raycast.ray_dir_x > 0)
		(*sprite) = game->assets.textures[ETEX];
	else if (game->raycast.hit_side == 1 && game->raycast.ray_dir_y > 0)
		(*sprite) = game->assets.textures[STEX];
	else
		(*sprite) = game->assets.textures[NTEX];
	text->x = (int)(wall_x * (double)sprite->w);
	if ((game->raycast.hit_side == 0 && game->raycast.ray_dir_x < 0)
		|| (game->raycast.hit_side == 1 && game->raycast.ray_dir_y > 0))
		text->x = sprite->w - text->x - 1;
}

static double	wall_hit_coordinate(t_game *game)
{
	double	coord;

	if (game->raycast.hit_side == 0)
		coord = game->player.pos_y
			+ game->wall_distance * game->raycast.ray_dir_y;
	else
		coord = game->player.pos_x
			+ game->wall_distance * game->raycast.ray_dir_x;
	coord -= floor(coord);
	return (coord);
}

static double	texture_y_coord(t_game *game, int wall_start_y,
		int screen_y, t_img sprite)
{
	double	screen_center;
	double	texture_offset;

	screen_center = (HEIGHT / 2.0) + game->player.look;
	texture_offset = wall_start_y - (int)screen_center
		+ (game->raycast.wall_height / 2);
	return (texture_offset * ((double)sprite.h / game->raycast.wall_height)
		+ (screen_y - wall_start_y) * ((double)sprite.h / game->raycast.wall_height));
}

static int	read_texture_pixel(t_img *sprite, t_point text)
{
	char	*pixel;

	if (text.x < 0 || text.y < 0 || text.x >= sprite->w || text.y >= sprite->h)
		return (0xFFFFFF);
	pixel = sprite->addr + (text.y * sprite->line_length
			+ text.x * (sprite->bits_per_pixel / 8));
	return (*(int *)pixel);
}

int	sample_wall_color(t_game *game, int wall_start_y, int screen_y)
{
	t_point	text;
	t_img	sprite;
	double	coord;

	coord = wall_hit_coordinate(game);
	choose_wall_texture(game, &sprite, &text, coord);
	text.y = (int)texture_y_coord(game, wall_start_y, screen_y, sprite)
		% sprite.h;
	if (text.y < 0)
		text.y += sprite.h;
	return (read_texture_pixel(&sprite, text));
}