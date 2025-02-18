#include "so_long.h"


void	ft_load_textures(t_game *game)
{
	int			size;

	size = TILE_SIZE;
	game->textures = malloc(sizeof(t_texture));
	if (!game->textures)
		ft_error("MEMORY ALLOCATION FAILED!");
	game->textures->empty_space = mlx_xpm_file_to_image(game->mlx_ptr, "resources/empty_space.xpm", &size, &size);
	if (!game->textures->empty_space)
		ft_error("FAILED TO LOAD TEXTURES(EMPTY SPACE)!");
	game->textures->wall = mlx_xpm_file_to_image(game->mlx_ptr, "resources/wall.xpm", &size, &size);
	if (!game->textures->wall)
		ft_error("FAILED TO LOAD TEXTURES(WALL)!");
	game->textures->collectible = mlx_xpm_file_to_image(game->mlx_ptr, "resources/collectible.xpm", &size, &size);
	if (!game->textures->collectible)
		ft_error("FAILED TO LOAD TEXTURES(COLLECTIBLE)!");
	game->textures->player = mlx_xpm_file_to_image(game->mlx_ptr, "resources/player.xpm", &size, &size);
	if (!game->textures->player)
		ft_error("FAILED TO LOAD TEXTURES(PLAYER)!");
	game->textures->exit = mlx_xpm_file_to_image(game->mlx_ptr, "resources/exit.xpm", &size, &size);
	if (!game->textures->exit)
		ft_error("FAILED TO LOAD TEXTURES(EXIT)!");
	game->textures->exit_open = mlx_xpm_file_to_image(game->mlx_ptr, "resources/exit_open.xpm", &size, &size);
	if (!game->textures->exit_open)
		ft_error("FAILED TO LOAD TEXTURES(EXIT_OPEN)!");
}
