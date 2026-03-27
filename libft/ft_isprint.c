/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:33:22 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:33:23 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// 32 to 126 (printable characters)
int	ft_isprint(char av)
{
	return (av >= 32 && av <= 126);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_isprint(av[1][0]));
} */