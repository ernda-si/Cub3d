#include "../../includes/struct.h"

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest [i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_safe_malloc(char **str, int position, size_t len)
{
	int	i;

	i = 0;
	str[position] = malloc(len + 1);
	if (str[position] == NULL)
	{
		while (i < position)
			free(str[i++]);
		free(str);
		return (1);
	}
	return (0);
}

static int	ft_wordcpy(char **str, char const *s)
{
	int	len;
	int	token;

	token = 0;
	while (*s)
	{
		len = 0;
		while (*s && ft_isspace(*s))
			s++;
		while (*s && !ft_isspace(*s))
		{
			s++;
			len++;
		}
		if (len != 0)
		{
			if (ft_safe_malloc(str, token, len))
				return (1);
			ft_strncpy(str[token], s - len, len);
			token++;
		}
	}
	return (0);
}

static size_t	ft_count_words(char const *s)
{
	int	j;
	int	i;
	int	signal;

	signal = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		while (s[i] && !ft_isspace(s[i]))
		{
			if (!signal)
			{
				j++;
				signal = 1;
			}
			i++;
		}
		signal = 0;
	}
	return (j);
}

char	**split_whitespaces(char const *s)
{
	size_t	words;
	char	**str;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	str = malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	str[words] = NULL;
	if (ft_wordcpy(str, s))
		return (NULL);
	return (str);
}
