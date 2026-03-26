#include "../../includes/cub3d.h"

static void	destroy_image_array(t_game *game, t_img *images, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (images[i].img)
			mlx_destroy_image(game->mlx, images[i].img);
		i++;
	}
}

static void	destroy_loaded_images(t_game *game)
{
	destroy_image_array(game, game->assets.textures, 4);
}

static void	destroy_runtime_resources(t_game *game)
{
	destroy_loaded_images(game);
	if (game->bg_img.img)
		mlx_destroy_image(game->mlx, game->bg_img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
}

int	closex(t_game *game)
{
	printf("\nClosing game...\n");
	destroy_runtime_resources(game);
	exit(0);
}

void	free_game(t_game *game)
{
	int	i;
	i = 0;
	if (game->assets.ceiling.nums)
		free(game->assets.ceiling.nums);
	if (game->assets.floor.nums)
		free(game->assets.floor.nums);
	if (game->map.grid)
		free_matrix(game->map.grid);
	if (game->map.flood_map)
		free_vmatrix((void **)game->map.flood_map);
	while (i < 4)
	{
		if (game->assets.textures[i].filename)
			free(game->assets.textures[i].filename);
		i++;
	}
}

