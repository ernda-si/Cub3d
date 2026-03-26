#include "libft.h"

int	ft_isalnum(char av)
{
	return ((av >= 'a' && av <= 'z') || (av >= 'A' && av <= 'Z') || \
	(av >= '0' && av <= '9'));
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_isalnum(av[1][0]));
} */