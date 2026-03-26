#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*vsrc;
	char	*vdest;
	size_t	i;

	vsrc = (char *) src;
	vdest = (char *) dest;
	i = 0;
	while (dest <= src && i < n)
	{
		vdest[i] = vsrc[i];
		i++;
	}
	while (dest > src && n--)
		vdest[n] = vsrc[n];
	return (vdest);
}

/* int main(void)
{
	char dest[] = "abcdef";
	char src[] = "123";

	printf("My memmove: %s\n", (char * )ft_memmove(dest, src, sizeof(char) * 2));
	printf("Original memmove: %s\n", (char *)memmove(dest, src, sizeof(char) * 2));
} */