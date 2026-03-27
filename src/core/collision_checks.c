/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:03:14 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:15 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	hit_box(t_game *game, double x, double y, int who)
{
	int		i;
	double	new_x;
	double	new_y;
	double	angle;

	(void)who;
	i = 0;
	while (i < ANGLE_NUMBERS)
	{
		angle = (2 * PI / ANGLE_NUMBERS) * i;
		new_x = x + cos(angle) * RADIUS;
		new_y = y + sin(angle) * RADIUS;
		if (game->map.grid[(int)new_y][(int)new_x] == '1' && who == 1)
			return (false);
		i++;
	}
	return (true);
}
