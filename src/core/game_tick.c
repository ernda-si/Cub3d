#include "../../includes/cub3d.h"

static void	running_loops(t_game *game)
{
	action(game);
	draw_frame(game);
}

int	main_loop(t_game *game)
{
	running_loops(game);
	return (0);
}
