#include "../../includes/cub3d.h"

static void	init_framebuffer(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!game->win)
		print_errors(game, 2, "Failed to create window");
	game->bg_img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->bg_img.img)
		print_errors(game, 2, "Failed to create image");
	game->bg_img.addr = mlx_get_data_addr(game->bg_img.img,
			&game->bg_img.bits_per_pixel, &game->bg_img.line_length,
			&game->bg_img.endian);
	if (!game->bg_img.addr)
		print_errors(game, 2, "Failed to access image data");
}

void	setup_render(t_game *game)
{
	game->player.speed = MOVE_SPEED;
	init_framebuffer(game);
	draw_frame(game);
}