/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:35:12 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/16 14:43:47 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_isvalid(const char *str)
{
	int	length;

	length = ft_strlen(str);
	if (ft_strncmp(&str[length - 4], ".ber", 4) != 0)
	{
		ft_error("INVALID FILE NAME/EXTENSION!");
		return (false);
	}
	return (true);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}

static void ft_init(t_game *game, char **map, t_info *map_info)
{
	game->mlx_ptr = mlx_init();
	ft_load_textures(game);
	game->count_colectibles = 2;
	game->win_ptr = mlx_new_window(game->mlx_ptr, map_info->width * TILE_SIZE, map_info->height * TILE_SIZE, "So long");
	ft_draw_map(game, map);
}

void	ft_start(t_game *game, char *map_name)
{
	char	**map;
	t_info	map_info;

	map = ft_load_map(map_name, &map_info);
	ft_init(game, map, &map_info);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
	if (map)
		ft_printf("MAP successfully loded!\n");
	ft_exit(map);
	mlx_loop(game->mlx_ptr);
}
