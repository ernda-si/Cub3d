/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:33:46 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:37:04 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*vsrc;
	char	*vdest;
	size_t	i;

	vsrc = (char *) src;
	vdest = (char *) dest;
	i = 0;
	while (dest <= src && i < n)
	{
		vdest[i] = vsrc[i];
		i++;
	}
	while (dest > src && n--)
		vdest[n] = vsrc[n];
	return (vdest);
}

/* int main(void)
{
	char dest[] = "abcdef";
	char src[] = "123";

	printf("My memmove: %s\n", (char * )ft_memmove(dest, src, sizeof(char) * 2));
	printf("Og memmove: %s\n", (char *)memmove(dest, src, sizeof(char) * 2));
} */