#include "../../includes/struct.h"

void    print_map(t_data *d)
{
    int y;

	y = 0;
    if (!d->map.grid)
    {
        printf("(map is NULL)\n");
        return;
    }
    printf("----- MAP DEBUG -----\n");
    while (d->map.grid[y])
    {
    	printf("%2d: \"%s\"\n", y, d->map.grid[y]);
		y++;
    }
    printf("---------------------\n");
}
