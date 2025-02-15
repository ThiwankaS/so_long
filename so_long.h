/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/14 05:25:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "ft_libft/libft.h"
# include "ft_libft/ft_printf.h"
# include "ft_libft/get_next_line.h"
# include "mlx_linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void *img;
	char *addr;
	int bites_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_points
{
	int x;
	int y;
} t_point;

#endif
