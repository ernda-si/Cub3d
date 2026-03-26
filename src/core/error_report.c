#include "../../includes/cub3d.h"

void	print_errors(t_game *game, int error, char *msg)
{
	if (msg != NULL)
		dprintf(2, "Error: %s\n", msg);
	if (error == 2)
		closex(game);
	if (game->fd > 2)
		close(game->fd);
	if (error == 1)
		free_game(game);
	exit(error);
}
