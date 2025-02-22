/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:43:39 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/22 02:04:53 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strconcat(char *s1, char *s2)
{
	int		count;
	int		step;
	char	*str;

	count = 0;
	step = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	while (s2 && s2[step])
	{
		str[count] = s2[step];
		count++;
		step++;
	}
	str[count] = '\0';
	return (str);
}

void	*ft_load(t_game *game, char *file_name)
{
	void	*ptr;
	char	*path;
	int		*width;
	int		*height;

	width = &game->img_width;
	height = &game->img_height;
	path = ft_strconcat("textures/", file_name);
	ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, width, height);
	free(path);
	return (ptr);
}

void	ft_load_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_texture));
	if (!game->textures)
		ft_error("MEMORY ALLOCATION FAILED!");
	game->textures->empty_space = ft_load(game, "empty_space.xpm");
	if (!game->textures->empty_space)
		ft_error("FAILED TO LOAD TEXTURES(EMPTY SPACE)!");
	game->textures->wall = ft_load(game, "wall.xpm");
	if (!game->textures->wall)
		ft_error("FAILED TO LOAD TEXTURES(WALL)!");
	game->textures->collectible = ft_load(game, "collectible.xpm");
	if (!game->textures->collectible)
		ft_error("FAILED TO LOAD TEXTURES(COLLECTIBLE)!");
	game->textures->player = ft_load(game, "player.xpm");
	if (!game->textures->player)
		ft_error("FAILED TO LOAD TEXTURES(PLAYER)!");
	game->textures->exit = ft_load(game, "exit.xpm");
	if (!game->textures->exit)
		ft_error("FAILED TO LOAD TEXTURES(EXIT)!");
	game->textures->exit_open = ft_load(game, "exit_open.xpm");
	if (!game->textures->exit_open)
		ft_error("FAILED TO LOAD TEXTURES(EXIT_OPEN)!");
}
