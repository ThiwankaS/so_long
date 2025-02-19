#include "so_long.h"

static	void ft_draw_texture(t_game *game, char **map, int x, int y)
{
	void	*img;

	img = NULL;
	if(map[y][x] == '1')
		img = game->textures->wall;
	else if(map[y][x] == '0')
		img = game->textures->empty_space;
	else if(map[y][x] == 'P')
		img = game->textures->player;
	else if(map[y][x] == 'E')
	{
		if(game->count_colectibles != 0)
			img = game->textures->exit_open;
		else
			img = game->textures->exit;
	}
	else if(map[y][x] == 'C')
		img = game->textures->collectible;
	if(img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

void ft_draw_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while(map[y])
	{
		while(map[y][x])
		{
			ft_draw_texture(game, map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
