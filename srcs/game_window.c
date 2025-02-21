/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:04:51 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 05:26:49 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}

int	ft_focus_out(void)
{
	return (0);
}

int	ft_focus_in(void)
{
	return (0);
}

int ft_exit_confirm_key(int keycode, t_game *game)
{
	if (keycode == KEY_YES)
		ft_cleanup(game);
	else if (keycode == KEY_NO)
		ft_close_window_confirmation(game);
	return (0);
}

int ft_exit_confirm_key_win(int keycode, t_game *game)
{
	if (keycode == KEY_OK)
	{
		ft_close_window_win(game);
		ft_cleanup(game);
	}
	return (0);
}

