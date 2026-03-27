/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:25:01 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:30:08 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TYPES_H
# define RENDER_TYPES_H

typedef struct s_player
{
	double				speed;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	int					look;
}					t_player;

typedef struct s_ray
{
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				delta_dist_x;
	double				delta_dist_y;
	int					step_x;
	int					step_y;
	double				side_dist_x;
	double				side_dist_y;
	int					hit_side;
	int					wall_height;
}					t_ray;

#endif