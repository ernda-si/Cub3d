/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:03:44 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:45 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

long	ft_atol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * sign);
}

static void	free_null_terminated_array(void **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_matrix(char **array)
{
	free_null_terminated_array((void **)array);
}

void	free_vmatrix(void **array)
{
	free_null_terminated_array(array);
}
