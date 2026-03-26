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
