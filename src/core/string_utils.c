/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:04:00 by mely-pan          #+#    #+#             */
/*   Updated: 2026/03/27 17:04:01 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

void	skip_wspaces(char **s)
{
	while (**s && (**s == ' ' || (**s >= 9 && **s <= 13)))
		(*s)++;
}

char	*get_word(char *s, char sep)
{
	size_t	len;

	skip_wspaces(&s);
	len = 0;
	while (s[len] && s[len] != sep && s[len] != '\n'
		&& !(s[len] >= 9 && s[len] <= 13))
		len++;
	return (ft_substr(s, 0, len));
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}
