/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:24:52 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:28:41 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_TYPES_H
# define BASE_TYPES_H

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				w;
	int				h;
	char			*filename;
}					t_img;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_pos
{
	double				x;
	double				y;
}					t_pos;

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	char			*nums;
	int				hexa;
}					t_color;

#endif