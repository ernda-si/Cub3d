/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:33:32 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:33:33 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*vstr;
	size_t		i;

	vstr = str;
	i = 0;
	while (i < n)
	{
		if (vstr[i] == (unsigned char)c || vstr[i] == c)
			return ((void *)&vstr[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*str = "Abacaxi";
	int		tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf ("Original memchr: %s\n", (char *)memchr(str, -1, 5));
	printf ("My memchr: %s\n", (char *)ft_memchr(str, -1, 5));

	printf("Original memchr2: %s\n", (char *)memchr(tab, -1, 7));
	printf("My memchr2: %s\n", (char *)ft_memchr(tab, -1, 7));
} */