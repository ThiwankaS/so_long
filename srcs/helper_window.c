/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:26:22 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 10:13:27 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window_confirmation(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->temp);
	return (0);
}

int	ft_close_window_win(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->temp);
	return (0);
}

int	ft_exit_confirmation(t_game *game)
{
	int		width;
	int		height;
	char	*s1;
	char	*s2;

	width = 250;
	height = 100;
	s1 = "Do you want to quit ?";
	s2 = "[Y] Yes  [N] No";
	game->temp = mlx_new_window(game->mlx_ptr, width, height, "Exit");
	mlx_string_put(game->mlx_ptr, game->temp, 70, 50, 0xFFFFFF, s1);
	mlx_string_put(game->mlx_ptr, game->temp, 90, 80, 0xFFFFFF, s2);
	mlx_hook(game->temp, 2, 1L << 0, ft_exit_confirm_key, game);
	return (0);
}

int	ft_win(t_game *game)
{
	int		width;
	int		height;
	char	*s1;
	char	*s2;

	width = 250;
	height = 100;
	game->count_moves++;
	s1 = "Congratulations, You won!";
	s2 = "[Press ENTER to Exit]";
	game->temp = mlx_new_window(game->mlx_ptr, width, height, "Exit");
	mlx_string_put(game->mlx_ptr, game->temp, 50, 50, 0xFFFFFF, s1);
	mlx_string_put(game->mlx_ptr, game->temp, 70, 80, 0xFFFFFF, s2);
	mlx_hook(game->temp, 2, 1L << 0, ft_exit_confirm_key_win, game);
	return (0);
}
