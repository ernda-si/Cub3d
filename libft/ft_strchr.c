/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:34:16 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:34:17 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (str[++i] != (unsigned char)c)
	{
		if (str[i] == '\0')
			return (NULL);
	}
	return (&str[i]);
}

/* int	main(void)
{
	printf("%s\n", strchr("tripouille", '0'));
	printf("%s\n", ft_strchr("tripouille", '0'));
} */
