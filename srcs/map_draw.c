/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 06:02:05 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw_texture(t_game *game, int x, int y)
{
	void	*img;
	int		dx;
	int		dy;

	dx = x * TILE_SIZE;
	dy = y * TILE_SIZE;
	img = NULL;
	if (game->map[y][x] == '1')
		img = game->textures->wall;
	else if (game->map[y][x] == '0')
		img = game->textures->empty_space;
	else if (game->map[y][x] == 'P')
		img = game->textures->player;
	else if (game->map[y][x] == 'E')
	{
		if (game->score != 0)
			img = game->textures->exit_open;
		else
			img = game->textures->exit;
	}
	else if (game->map[y][x] == 'C')
		img = game->textures->collectible;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, dx, dy);
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
