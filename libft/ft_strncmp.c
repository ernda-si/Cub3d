/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:34:47 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:34:48 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *str1, char const *str2, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = ft_strlen(str1) + ft_strlen(str2);
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < (n - 1) && str1[i] && str2[i])
	{
		if (str1[i] > 126 || str2[i] > 126 || str2[i] == '\0')
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	
	printf("My: %d\n", ft_strncmp(av[1], av[2], 42));
	printf("Original: %d\n", strncmp(av[1], av[2], 42));
} */
