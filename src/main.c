#include "../includes/struct.h"

int	main(int argc, char **argv)
{
	//Define structs
	t_parse	parse;
	// t_map map;

	(void)argc;
	(void)argv;
	//Dev A
	validate_args(argc, argv);
	parse_file(argv[1], &parse);

	//Dev B
	// init_game();
	// init_mlx();
	// game_loop();

	// //Dev A + B
	// handle_exit();
}