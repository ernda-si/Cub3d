#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_isalpha(av[1][0]));
} */
