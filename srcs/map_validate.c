/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:44:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 06:14:58 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_charaters(char **map, t_info *map_info, int x, int y)
{
	while (map[y][x])
	{
		while (map[y][x])
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
		map_info->width = x;
		y++;
		x = 0;
	}
	map_info->height = y;
}

static int	ft_valid_characters(char **map, t_info *map_info)
{
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
	int	y;

	if (map_info->width <= map_info->height)
		ft_error("INVALID MAP (SHOULD BE RECTANGULAR)!");
	else
	{
		y = 0;
		while (y < map_info->height)
		{
			x = 0;
			while (map[y][x])
				x++;
			if (x != map_info->width)
				ft_error("INVALID MAP (SHOULD BE RECTANGULAR)!");
			y++;
		}
	}
	return (1);
}

static int	ft_surrounded_walls(char **map, t_info *map_info, int x, int y)
{
	while (x < map_info->width - 1)
	{
		if (map[y][x] != '1')
			ft_error("INVALID MAP (SHOULD SURROUNDED BY WALLS)!");
		x++;
	}
	y++;
	while (y < map_info->height)
	{
		if (map[y][0] != '1' || map[y][map_info->width - 2] != '1')
			ft_error("INVALID MAP (SHOULD SURROUNDED BY WALLS)!");
		y++;
	}
	y = map_info->height - 1;
	while (x < map_info->width - 1)
	{
		if (map[y][x] != '1')
			ft_error("INVALID MAP (SHOULD SURROUNDED BY WALLS)!");
		x++;
	}
	return (1);
}

bool	ft_map_validate(char **map, t_info *map_info)
{
	ft_map_info_init(map_info);
	ft_valid_characters(map, map_info);
	ft_is_rectangular(map, map_info);
	ft_surrounded_walls(map, map_info, 0, 0);
	ft_contains_valid_path(map, map_info);
	return (true);
}
