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

// static void ft_init(t_game *game)
// {
// 	game->mlx_ptr = mlx_init();
// 	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Test window");
// }

void	ft_start(t_game *game, char *map_name)
{
	char	**map;

	(void)game;
	// ft_init(game);
	// mlx_hook(game->win_ptr, 17, 0, close_window, game);
	map = ft_load_map(map_name);
	if (map)
		ft_printf("MAP successfully loded!\n");
	ft_exit(map);
	//mlx_loop(game->mlx_ptr);
}
