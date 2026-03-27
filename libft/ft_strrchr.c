/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:34:55 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:34:56 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != (unsigned char)c && i != 0)
		i--;
	if (i == 0 && str[i] != (unsigned char)c)
		return (NULL);
	return (&str[i]);
}
// 5 8 issues //
/* int	main(void)
{
	printf("%s\n", ft_strrchr("abacaxi", ' '));
	printf("%s\n", strrchr("abacaxi", ' '));
} */
