/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:44:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/22 09:49:36 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_charaters(char **map, t_info *map_info, int x, int y)
{
	while (y < map_info->height)
	{
		while (x < map_info->width)
		{
			if (map[y][x] == 'P')
				map_info->p_count++;
			else if (map[y][x] == 'C')
				map_info->c_count++;
			else if (map[y][x] == 'E')
				map_info->e_count++;
			else if (map[y][x] == '1')
				map_info->w_count++;
			else if (map[y][x] == '0')
				map_info->s_count++;
			else if (map[y][x] != '\n' && map[y][x] != '\0')
				ft_error("INVALID MAP(UNKNOWN CHARACTER)!");
			x++;
		}
		x = 0;
		y++;
	}
}

static int	ft_valid_characters(char **map, t_info *map_info)
{
	if (!map)
		ft_error("INVALID MAP!");
	ft_count_charaters(map, map_info, 0, 0);
	if (map_info->width < 1 || map_info->c_count < 1 || map_info->s_count < 1)
		ft_error("INVALID MAP (SHOULD CONTAIN ALL COMPONENTS)!");
	else if (map_info->p_count != 1)
		ft_error("INVALID MAP (SHOULD CONTAIN ONLY ONE STARTING POINT)!");
	else if (map_info->e_count != 1)
		ft_error("INVALID MAP (SHOULD CONTAIN ONLY ONE EXIT POINT)!");
	else if (map_info->c_count < 1)
		ft_error("INVALID MAP (SHOULD CONTAIN AT LEAST ONE COLLECTIBLE)!");
	return (1);
}

static int	ft_is_rectangular(char **map, t_info *map_info)
{
	int	x;
	int	length;

	if (map_info->width == map_info->height)
		ft_error("INVALID MAP (SHOULD BE RECTANGULAR)!");
	else
	{
		x = 0;
		while (x < map_info->height)
		{
			length = ft_strlen(map[x]);
			if (length != map_info->width)
				ft_error("INVALID MAP (SHOULD BE RECTANGULAR 02)!");
			x++;
		}
	}
	return (1);
}

static int	ft_surrounded_walls(char **map, t_info *map_info, int x, int y)
{
	while (x < map_info->width)
	{
		if (map[y][x] != '1')
			ft_error("INVALID MAP (SHOULD SURROUNDED BY WALLS 1)!");
		x++;
	}
	y++;
	while (y < map_info->height)
	{
		if (map[y][0] != '1' || map[y][map_info->width - 1] != '1')
			ft_error("INVALID MAP (SHOULD SURROUNDED BY WALLS 2)!");
		y++;
	}
	x = 0;
	y = map_info->height - 1;
	while (x < map_info->width)
	{
		if (map[y][x] != '1')
			ft_error("INVALID MAP (SHOULD SURROUNDED BY WALLS)!");
		x++;
	}
	return (1);
}

bool	ft_map_validate(char **map, t_info *map_info)
{
	ft_map_info_init(map_info, map);
	ft_valid_characters(map, map_info);
	ft_is_rectangular(map, map_info);
	ft_surrounded_walls(map, map_info, 0, 0);
	ft_contains_valid_path(map, map_info);
	return (true);
}
