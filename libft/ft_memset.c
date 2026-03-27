/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:33:50 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:33:51 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*vptr;

	vptr = ptr;
	while (n--)
	{
		*vptr++ = x;
	}
	if (*vptr == '\0')
		return (NULL);
	return (ptr);
}
/* 
int	main(void)
{
	char ptr[] = "abcdef";
	printf("Original memset: %s\n", memset(ptr, 42, 3));
	printf("My memset: %s\n", ft_memset(ptr, 42, 3));
} */