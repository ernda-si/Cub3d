#ifndef CUB3D_WORLD_TYPES_H
# define CUB3D_WORLD_TYPES_H

typedef struct s_assets
{
	t_img			textures[4];
	t_color			ceiling;
	t_color			floor;
} 					t_assets;

typedef struct s_map
{
	char				**flood_map;
	char				**grid;
	int				breakp;
	t_pos				pos;
	bool				exists;
	int				height;
} 					t_map;

#endif