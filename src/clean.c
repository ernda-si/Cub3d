#include "../includes/struct.h"

void	clean_textures(t_parse *data)
{
	if (data->no)
		free(data->no);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->so)
		free(data->so);
}

void	parse_error(char *str, t_parse *data)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (data)
	{
		clean_textures(data);
		if (data->fd > 0)
			close(data->fd);
	}
	exit(1);
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
