/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:33:02 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:33:03 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	s = malloc (nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero (s, nmemb * size);
	return (s);
}

/* int	main(void)
{
	printf("Original calloc: %s\n", (char *)calloc(-5, -5));
	printf("My calloc: %s\n", (char *)ft_calloc(-5, -5));
} */