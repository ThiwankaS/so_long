/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:11 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/25 04:43:41 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_player(t_game *game, int x, int y)
{
	int	dx;
	int	dy;

	dx = game->player->x + x;
	dy = game->player->y + y;
	if (game->map[dy][dx] == '1')
		return (1);
	if (game->map[dy][dx] == 'C')
		game->score++;
	if (game->map[dy][dx] == 'E')
	{
		if (game->score == game->map_info->c_count)
			ft_close_window(game);
	}
	else
	{
		game->map[dy][dx] = 'P';
		game->map[game->player->y][game->player->x] = '0';
		game->player->x = dx;
		game->player->y = dy;
		game->count_moves++;
	}
	ft_printf("No of moves : %d\n", game->count_moves);
	ft_draw_map(game);
	return (1);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move_player(game, 1, 0);
	else if (keycode == KEY_ESC)
		ft_close_window(game);
	return (0);
}
