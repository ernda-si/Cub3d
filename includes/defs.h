/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:24:30 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:25:56 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <math.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 700
# define MOVE_SPEED 0.025

# define PI 3.14159265358979323846
# define RADIUS 0.1
# define ANGLE_NUMBERS 8
# define ROT_SPEED 0.0008
# define ARROW_ROT_SPEED 0.06

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define NTEX 0
# define ETEX 1
# define WTEX 2
# define STEX 3

#endif