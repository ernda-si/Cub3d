#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H

# include "types.h"

// loop helpers
int					main_loop(t_game *game);

// generation
void				setup_render(t_game *game);
void				render_columns(t_game *game);
void				init_column_ray(t_game *game, int screen_x);
void				init_dda(t_game *game);
int					find_wall_hit(t_game *game);
double				compute_wall_dist(t_game *game);
void				compute_wall_slice(t_game *game, double wall_dist,
						int *wall_start_y, int *wall_end_y);
void				draw_frame(t_game *game);
void				draw_vertical_slice(t_game *game, int screen_x,
						int wall_start_y, int wall_end_y);
int					sample_wall_color(t_game *game, int wall_start_y,
						int screen_y);

// clean
int					closex(t_game *mlx);

// mlx_adds
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);

// events
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					action(t_game *game);
void				move_forward(t_game *game, double speed);
void				move_back(t_game *game, double speed);
void				move_left(t_game *game, double speed);
void				move_right(t_game *game, double speed);
void				look_right(t_game *game);
void				look_left(t_game *game);
bool				hit_box(t_game *game, double x, double y, int who);

// parse
bool				parse(t_game *game, char *filename);
void				print_errors(t_game *game, int error, char *msg);
void				free_game(t_game *game);
void				init_vars(t_game *game);
char				*get_textures(t_game *game);
bool				check_texture(char *line, char **img, char c);
char				**letters_init(void);
void				parse_colors(t_game *game);
bool				skip_comma(t_color *colors, int *i, bool last_check);
bool				get_colors(t_color *colors);
bool				check_colors(t_color colors);
int					color_hexa(t_game *game, t_color color);
void				parse_map(t_game *game, char *filename, char *line);
bool				get_map(t_game *game, char *filename, char *line);
bool				flood_map(t_map *map, int x, int y);
bool				get_player(t_game *game);
int					convert_dec(char *hexa);
void				convert_hexa(int color, char **result, char *base, int *i);

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *haystack, const char *needle);
long				ft_atol(const char *str);
void				skip_wspaces(char **s);
char				*get_word(char *s, char sep);
char				*ft_strjoin2(char *s1, char *s2);
void				free_matrix(char **array);
void				free_vmatrix(void **array);

int					textures(t_game *game);
void				img_init(t_game *game, char *filename, t_img *img);

#endif