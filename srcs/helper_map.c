/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:32 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 02:55:54 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_info_init(char **map, t_info *map_info)
{
	map_info->c_count = 0;
	map_info->e_count = 0;
	map_info->p_count = 0;
	map_info->s_count = 0;
	map_info->w_count = 0;
	map_info->w_count = 0;
	map_info->width = ft_get_width(map);
	map_info->height = ft_get_height(map);
	return (1);
}

void	ft_configure_vars(t_game *game)
{
	game->player = malloc(sizeof(t_position));
	if (!game->player)
		ft_clear(game, "MEMORY ALLOCATION FALIUR!");
	game->exit = malloc(sizeof(t_position));
	if (!game->exit)
		ft_clear(game, "MEMORY ALLOCATION FALIUR!");
	game->player->type = 'P';
	ft_set_point(game->map, 'P', &game->player->x, &game->player->y);
	game->exit->type = 'E';
	ft_set_point(game->map, 'E', &game->exit->x, &game->exit->y);
	game->score = 0;
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	count;

	count = 0;
	while (src && src[count] && (n - count))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

int	ft_count_nl(char *str)
{
	int	count;

	count = 0;
	while (str && str[count] && str[count] != '\n')
		count++;
	return (count);
}

bool	ft_valid_char(char c)
{
	if (c == 'P')
		return (true);
	else if (c == 'C')
		return (true);
	else if (c == 'E')
		return (true);
	else if (c == '1')
		return (true);
	else if (c == '0')
		return (true);
	else if (c == '\n')
		return (true);
	else if (c == '\0')
		return (true);
	else
		return (false);
}
