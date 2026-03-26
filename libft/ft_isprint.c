#include "libft.h"
// 32 to 126 (printable characters)
int	ft_isprint(char av)
{
	return (av >= 32 && av <= 126);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_isprint(av[1][0]));
} */