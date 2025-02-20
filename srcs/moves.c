/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:11 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/20 15:42:49 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_ESC 65307

static int ft_move_player(t_game *game, int x, int y)
{
	int dx;
	int dy;
	int cur_x;
	int cur_y;

	cur_x = game->player->x;
	cur_y = game->player->y;

	dx = cur_x + x;
	dy = cur_y + y;

	if(game->map[dy][dx] == '1')
		return (1);
	if(game->map[dy][dx] == 'C')
		game->score++;
	game->map[dy][dx] = 'P';
	game->player->x = dx;
	game->player->y = dy;
	game->map[cur_y][cur_x] = '0';
	game->count_moves++;
	ft_draw_map(game);
	return (1);
}

int	ft_key_press(int keycode, t_game *game)
{
	if(keycode == KEY_W || keycode == KEY_UP)
		ft_move_player(game, 0, -1);
	else if(keycode == KEY_S || keycode == KEY_DOWN)
		ft_move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move_player(game, 1, 0);
	return (0);
}
