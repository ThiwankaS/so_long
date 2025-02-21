/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:43:39 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 03:43:45 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_texture));
	if (!game->textures)
		ft_error("MEMORY ALLOCATION FAILED!");
	game->textures->empty_space = mlx_xpm_file_to_image(game->mlx_ptr, "resources/empty_space.xpm", &game->img_width, &game->img_height);
	if (!game->textures->empty_space)
		ft_error("FAILED TO LOAD TEXTURES(EMPTY SPACE)!");
	game->textures->wall = mlx_xpm_file_to_image(game->mlx_ptr, "resources/wall.xpm", &game->img_width, &game->img_height);
	if (!game->textures->wall)
		ft_error("FAILED TO LOAD TEXTURES(WALL)!");
	game->textures->collectible = mlx_xpm_file_to_image(game->mlx_ptr, "resources/collectible.xpm", &game->img_width, &game->img_height);
	if (!game->textures->collectible)
		ft_error("FAILED TO LOAD TEXTURES(COLLECTIBLE)!");
	game->textures->player = mlx_xpm_file_to_image(game->mlx_ptr, "resources/player.xpm", &game->img_width, &game->img_height);
	if (!game->textures->player)
		ft_error("FAILED TO LOAD TEXTURES(PLAYER)!");
	game->textures->exit = mlx_xpm_file_to_image(game->mlx_ptr, "resources/exit.xpm", &game->img_width, &game->img_height);
	if (!game->textures->exit)
		ft_error("FAILED TO LOAD TEXTURES(EXIT)!");
	game->textures->exit_open = mlx_xpm_file_to_image(game->mlx_ptr, "resources/exit_open.xpm", &game->img_width, &game->img_height);
	if (!game->textures->exit_open)
		ft_error("FAILED TO LOAD TEXTURES(EXIT_OPEN)!");
}
