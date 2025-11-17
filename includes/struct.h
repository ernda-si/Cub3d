#ifndef STRUCT_H
#define STRUCT_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdbool.h>

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	hex;
} t_rgb;

typedef struct s_parse
{
	int		fd;
    char    *no;
    char    *so;
    char    *ea;
    char    *we;
	t_rgb	floor;
	t_rgb	ceiling;
	bool	floor_set;
	bool	ceiling_set;

	char	**map;
	char	*file_line;
	size_t	map_width;
	size_t	map_height;
	int		player_x;
	int		player_y;
	char	player_dir;
	bool	map_started;
	bool	map_ended;
} t_parse;

typedef struct s_map {

    // ...

} t_map;

/*              Exit && Clean FUNCTIONS            */
void	free_split(char **args);
void	parse_error(char *str, t_parse *data);

/*				PARSE FUNCTIONS				*/
void	handle_empty_line(t_parse *parse);
void	parse_file(char	*file, t_parse *parse);
void	parse_map_line(char *line, t_parse *parse);
void	parse_texture_line(char *line, t_parse *parse);
void	validate_args(int ac, char **av);
void	validate_textures_and_colors(t_parse *parse);
void	validate_map(t_parse *parse);
void	check_closed_map(t_parse *parse);
bool	is_texture_line(char *line);
bool	is_empty_line(char *line);

/*					UTILS					*/
int		ft_isspace(char c);
int		check_digits(char *arg);
char	**split_whitespaces(char const *s);

#endif