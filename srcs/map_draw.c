/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 03:16:00 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw_texture(t_game *game, int x, int y)
{
	int		dx;
	int		dy;
	void	*ptr;

	dx = x * TILE_SIZE;
	dy = y * TILE_SIZE;
	ptr = game->mlx_ptr;
	if (game->map[y][x] == '1')
		game->img = game->textures->wall;
	else if (game->map[y][x] == '0')
		game->img = game->textures->empty_space;
	else if (game->map[y][x] == 'P')
		game->img = game->textures->player;
	else if (game->map[y][x] == 'E')
	{
		if (game->score == game->map_info->c_count)
			game->img = game->textures->exit_open;
		else
			game->img = game->textures->exit;
	}
	else if (game->map[y][x] == 'C')
		game->img = game->textures->collectible;
	if (game->img)
		mlx_put_image_to_window(ptr, game->win_ptr, game->img, dx, dy);
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			ft_draw_texture(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
