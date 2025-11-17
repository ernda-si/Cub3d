#include "../../includes/struct.h"

void    print_map(t_parse *p)
{
    int y;

	y = 0;
    if (!p->map)
    {
        printf("(map is NULL)\n");
        return;
    }
    printf("----- MAP DEBUG -----\n");
    while (p->map[y])
    {
    	printf("%2d: \"%s\"\n", y, p->map[y]);
		y++;
    }
    printf("---------------------\n");
}
