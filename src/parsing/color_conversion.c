/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:04:10 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:04:11 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	convert_dec(char *hexa)
{
	int	digit;
	int	value;
	int	i;

	value = 0;
	i = 0;
	digit = 0;
	while (hexa[i])
	{
		if (hexa[i] && hexa[i] >= '0' && hexa[i] <= '9')
			digit = hexa[i] - '0';
		else
			digit = 10 + (hexa[i] - 'A');
		value = value * 16 + digit;
		i++;
	}
	return (value);
}

void	convert_hexa(int color, char **result, char *base, int *i)
{
	int	hex_digit_index;

	if (color > 16)
	{
		convert_hexa(color / 16, result, base, i);
		(*i)++;
	}
	hex_digit_index = color % 16;
	(*result)[*i] = base[hex_digit_index];
}

int	color_hexa(t_game *game, t_color color)
{
	(void)game;
	return ((color.red << 16) | (color.green << 8) | color.blue);
}
