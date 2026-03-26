#include "../../includes/cub3d.h"

void	put_frame_pixel(t_game *game, int screen_x, int screen_y, int color)
{
	my_mlx_pixel_put(&game->bg_img, screen_x, screen_y, color);
}

void	draw_vertical_slice(t_game *game, int screen_x,
		int wall_start_y, int wall_end_y)
{
	int	color;
	int	screen_y;

	screen_y = -1;
	while (++screen_y < HEIGHT)
	{
		if (screen_y < wall_start_y)
			put_frame_pixel(game, screen_x, screen_y, game->assets.ceiling.hexa);
		else if (screen_y <= wall_end_y)
		{
			color = sample_wall_color(game, wall_start_y, screen_y);
			put_frame_pixel(game, screen_x, screen_y, color);
		}
		else
			put_frame_pixel(game, screen_x, screen_y, game->assets.floor.hexa);
	}
}