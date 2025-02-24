/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:54:24 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 02:56:41 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clean_textures(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->collectible)
			mlx_destroy_image(game->mlx_ptr, game->textures->collectible);
		if (game->textures->empty_space)
			mlx_destroy_image(game->mlx_ptr, game->textures->empty_space);
		if (game->textures->exit)
			mlx_destroy_image(game->mlx_ptr, game->textures->exit);
		if (game->textures->exit_open)
			mlx_destroy_image(game->mlx_ptr, game->textures->exit_open);
		if (game->textures->player)
			mlx_destroy_image(game->mlx_ptr, game->textures->player);
		if (game->textures->wall)
			mlx_destroy_image(game->mlx_ptr, game->textures->wall);
		free(game->textures);
	}
	return (1);
}

int	ft_clean_game(t_game *game)
{
	if (game)
	{
		if (game->player)
			free(game->player);
		if (game->exit)
			free(game->exit);
		if (game->map_info)
			free(game->map_info);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
			free(game->mlx_ptr);
		free(game);
	}
	return (1);
}
