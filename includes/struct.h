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

typedef	struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
} t_map;

typedef	struct s_player
{
    int     x;
    int     y;
    char    dir;
} t_player;

typedef struct s_data
{
	int			fd;
    char    	*no;
    char    	*so;
    char    	*ea;
    char    	*we;
	t_rgb		floor;
	t_rgb		ceiling;
	bool		floor_set;
	bool		ceiling_set;
	t_player	player;
	t_map		map;
	char		*file_line;
	bool		map_started;
	bool		map_ended;
} t_data;

/*              Exit && Clean FUNCTIONS            */
void	free_split(char **args);
void	parse_error(char *str, t_data *data);

/*				PARSE FUNCTIONS				*/
void	handle_empty_line(t_data *parse);
void	parse_file(char	*file, t_data *parse);
void	parse_map_line(char *line, t_data *parse);
void	parse_texture_line(char *line, t_data *parse);
void	validate_args(int ac, char **av);
void	validate_textures_and_colors(t_data *parse);
void	validate_map(t_data *parse);
void	check_closed_map(t_data *parse);
bool	is_texture_line(char *line);
bool	is_empty_line(char *line);

/*					UTILS					*/
int		ft_isspace(char c);
int		check_digits(char *arg);
char	**split_whitespaces(char const *s);

/*					DEBUG					*/
void	print_map(t_data *parse);

#endif