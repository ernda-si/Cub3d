#include "../../includes/cub3d.h"

void	img_init(t_game *game, char *filename, t_img *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx, filename, &img->w, &img->h);
	if (img->img == NULL)
	{
		dprintf(2, "Error: failed to load %s\n", filename);
		closex(game);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
	{
		dprintf(2, "Error: failed to read data from %s\n", filename);
		closex(game);
	}
}

int	textures(t_game *game)
{
	img_init(game, game->assets.textures[NTEX].filename, &game->assets.textures[NTEX]);
	img_init(game, game->assets.textures[ETEX].filename, &game->assets.textures[ETEX]);
	img_init(game, game->assets.textures[WTEX].filename, &game->assets.textures[WTEX]);
	img_init(game, game->assets.textures[STEX].filename, &game->assets.textures[STEX]);
	return (1);
}
