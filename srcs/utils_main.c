#include "so_long.h"

int	ft_error(char *msg)
{
	ft_printf("Error\n : %s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_start(t_game *game)
{
	ft_printf("width : %d\n", game->width);
	ft_printf("height : %d\n", game->height);
}

void	ft_cleanup(t_game *game)
{
	game->height = 1000;
	game->width = 2000;
	ft_printf("width : %d\n", game->width);
	ft_printf("height : %d\n", game->height);
}
