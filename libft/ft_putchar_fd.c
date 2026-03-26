#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

/* int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	printf ("char: %c\n", ft_putchar_fd(NULL, 1));
} */