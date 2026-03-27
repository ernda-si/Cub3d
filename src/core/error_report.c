/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:03:20 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:21 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_errors(t_game *game, int error, char *msg)
{
	if (msg != NULL)
		dprintf(2, "Error: %s\n", msg);
	if (error == 2)
		closex(game);
	if (game->fd > 2)
		close(game->fd);
	if (error == 1)
		free_game(game);
	exit(error);
}
