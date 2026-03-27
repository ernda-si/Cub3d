/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:32:58 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:35:52 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*vs;

	vs = s;
	while (s && n--)
		*vs++ = '\0';
}

/*int	main(void)
 {
 	char	s[] = "Abacaxi";
	bzero (s + 3, 7);
	printf("Original: %s\n", s);

	char	s2[] = "Abacaxi";
	ft_bzero(s2 + 3, 7);
	printf("My bzero: %s\n", s2);
} */
