/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:25:05 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:30:24 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_TYPES_H
# define WORLD_TYPES_H

typedef struct s_assets
{
	t_img			textures[4];
	t_color			ceiling;
	t_color			floor;
}					t_assets;

typedef struct s_map
{
	char				**flood_map;
	char				**grid;
	int					breakp;
	t_pos				pos;
	bool				exists;
	int					height;
}					t_map;

#endif