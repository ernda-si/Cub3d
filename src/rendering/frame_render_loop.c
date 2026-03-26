#include "../../includes/cub3d.h"

void	render_columns(t_game *game)
{
	int	wall_start_y;
	int	wall_end_y;
	int	screen_x;

	screen_x = 0;
	while (screen_x < WIDTH)
	{
		init_column_ray(game, screen_x);
		init_dda(game);
		game->raycast.hit_side = find_wall_hit(game);
		game->wall_distance = compute_wall_dist(game);
		compute_wall_slice(game, game->wall_distance,
			&wall_start_y, &wall_end_y);
		draw_vertical_slice(game, screen_x, wall_start_y, wall_end_y);
		screen_x++;
	}
}

void	draw_frame(t_game *game)
{
	render_columns(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->bg_img.img, 0, 0);
}