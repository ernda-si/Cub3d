#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	char		*vdest;
	char const	*vsrc;
	size_t		i;

	vdest = dest;
	vsrc = src;
	i = 0;
	while (n--)
	{
		vdest[i] = vsrc[i];
		i++;
	}
	return (vdest);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("Original memcpy: %p\n", memcpy(av[1], av[2], 3));
	printf("My memcpy: %p\n", ft_memcpy (av[1], av[2], 3));
} */
