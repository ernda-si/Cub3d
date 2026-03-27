/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:35:00 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 21:35:01 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	while ((ft_strchr(set, s1[end])))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

/* int	main(void)
{
	if (!ft_strtrim(NULL, "ok"))
		return (printf("failed\n"));
	else
		sprintf("%s\n", ft_strtrim(NULL , "ok"));
} */