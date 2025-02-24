/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:44:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 02:55:42 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_count_charaters(char **map, t_info *info, int x, int y)
{
	while (y < info->height)
	{
		while (x < info->width && ft_valid_char(map[y][x]))
		{
			if (!ft_valid_char(map[y][x]))
				return (false);
			if (map[y][x] == 'P')
				info->p_count++;
			else if (map[y][x] == 'C')
				info->c_count++;
			else if (map[y][x] == 'E')
				info->e_count++;
			else if (map[y][x] == '1')
				info->w_count++;
			else if (map[y][x] == '0')
				info->s_count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}

static bool	ft_valid_characters(char **map, t_info *info)
{
	if (!map)
		return (false);
	if (!ft_count_charaters(map, info, 0, 0))
		return (false);
	if (info->width < 1 || info->c_count < 1 || info->s_count < 1)
		return (false);
	if (info->p_count != 1)
		return (false);
	if (info->e_count != 1)
		return (false);
	if (info->c_count < 1)
		return (false);
	return (true);
}

static bool	ft_is_rectangular(char **map, t_info *info)
{
	int	x;
	int	length;

	if (info->width == info->height)
		return (false);
	else
	{
		x = 0;
		while (x < info->height)
		{
			length = ft_strlen(map[x]);
			if (length != info->width)
				return (false);
			x++;
		}
	}
	return (true);
}

static bool	ft_surrounded_walls(char **map, t_info *info, int x, int y)
{
	while (x < info->width)
	{
		if (map[y][x] != '1')
			return (false);
		x++;
	}
	y++;
	while (y < info->height)
	{
		if (map[y][0] != '1' || map[y][info->width - 1] != '1')
			return (false);
		y++;
	}
	x = 0;
	y = info->height - 1;
	while (x < info->width)
	{
		if (map[y][x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	ft_map_validate(char **map, t_info *info)
{
	if (!ft_valid_characters(map, info))
		return (false);
	if (!ft_is_rectangular(map, info))
		return (false);
	if (!ft_surrounded_walls(map, info, 0, 0))
		return (false);
	if (!ft_contains_valid_path(map, info))
		return (false);
	return (true);
}
