/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:32 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/22 13:15:41 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_info_init(t_info *map_info, char **map)
{
	map_info->c_count = 0;
	map_info->e_count = 0;
	map_info->p_count = 0;
	map_info->s_count = 0;
	map_info->w_count = 0;
	map_info->w_count = 0;
	map_info->width = ft_get_width(map);
	map_info->height = ft_get_height(map);
}

void	ft_configure_vars(t_game *game, char **map, t_info *map_info)
{
	t_position	*player_position;
	t_position	*exit_position;

	player_position = malloc(sizeof(t_position));
	if (!player_position)
		ft_error("MEMORY ALLOCATION FALIUR!");
	exit_position = malloc(sizeof(t_position));
	if (!exit_position)
		ft_error("MEMORY ALLOCATION FALIUR!");
	player_position->type = 'P';
	ft_set_point(map, 'P', &player_position->x, &player_position->y);
	exit_position->type = 'E';
	ft_set_point(map, 'E', &exit_position->x, &exit_position->y);
	game->player = player_position;
	game->exit = exit_position;
	game->score = 0;
	game->map = map;
	game->map_info = map_info;
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
