/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:35:12 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 02:36:44 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_isvalid(const char *str)
{
	int	length;

	if (!str)
		return (false);
	length = ft_strlen(str);
	if (ft_strncmp(&str[length - 4], ".ber", 4) != 0)
	{
		ft_error("INVALID FILE NAME/EXTENSION!");
		return (false);
	}
	return (true);
}

static void	ft_init(t_game *game)
{
	int	width;
	int	height;
	int	tile_size;

	width = (game->map_info->width) * TILE_SIZE;
	height = game->map_info->height * TILE_SIZE;
	tile_size = TILE_SIZE;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_clear(game, "FAILED TO INITILIZED MLX_PTR!");
	ft_configure_vars(game);
	ft_set_window_size(game, &width, &height, &tile_size);
	ft_load_textures(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "So long");
	if (!game->win_ptr)
		ft_clear(game, "FAILED TO INITILIZED WIN_PTR!");
	ft_draw_map(game);
	ft_hooks(game);
}

void	ft_start(t_game *game, char *map_name)
{
	game->map_info = malloc(sizeof(t_info));
	if (!game->map_info)
		ft_clear(game, "MEMORY ALLOCATION FALIUR!");
	ft_load_map(game, map_name);
	if (!game->map)
		ft_clear(game, "UNABLE TO LOAD THE MAP!");
	ft_map_info_init(game->map, game->map_info);
	if (!ft_map_validate(game->map, game->map_info))
		ft_clear(game, "INVALID MAP!");
	ft_init(game);
	mlx_loop(game->mlx_ptr);
}
