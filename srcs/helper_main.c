/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:35:12 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 04:05:14 by tsomacha         ###   ########.fr       */
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

static void ft_init(t_game *game, char **map, t_info *map_info)
{
	game->mlx_ptr = mlx_init();
	ft_load_textures(game);
	ft_configure_vars(game, map, map_info);
	game->win_ptr = mlx_new_window(game->mlx_ptr, map_info->width * TILE_SIZE, map_info->height * TILE_SIZE, "So long");
	ft_draw_map(game);
	ft_hooks(game);
}

void	ft_start(t_game *game, char *map_name)
{
	char	**map;
	t_info	*map_info;

	map_info = malloc(sizeof(t_info));
	if(!map_info)
		ft_error("MEMORY ALLOCATION FALIUR!");
	map = ft_load_map(map_name, map_info);
	if (!map)
		ft_printf("UNABLE TO LOAD THE MAP\n");
	ft_init(game, map, map_info);
	mlx_loop(game->mlx_ptr);
	ft_exit(map);
}
