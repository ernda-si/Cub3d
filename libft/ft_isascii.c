#include "libft.h"

int	ft_isascii(int av)
{
	return (av >= 0 && av <= 127);
}

/* int	main(int ac, char **av)
{
	printf("%d\n", ac);
	printf("%d\n", ft_isascii(av[1][0]));
} */
