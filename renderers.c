/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:48:19 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/14 14:41:37 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_from_grid(t_mlx_data *data, int x, int y);

void	create_grid(t_mlx_data *mlx)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < mlx->map.height)
	{
		pos.x = 0;
		while (pos.x < mlx->map.width)
		{
			put_image_from_grid(mlx, pos.x, pos.y);
			(pos.x)++;
		}
		(pos.y)++;
	}
}

void	put_image_from_grid(t_mlx_data *data, int x, int y)
{
	void	*img;
	int		offset_left;
	int		offset_top;

	if (data->map.map[y][x] == WALL)
		img = data->wall;
	if (data->map.map[y][x] == EMPTY)
		img = data->empty;
	if (data->map.map[y][x] == COLLECT)
		img = data->coll;
	if (data->map.map[y][x] == DOOR)
		img = data->door;
	if (data->map.map[y][x] == PLAYER)
		img = data->player;
	offset_left = data->map.offs.x + data->map.c_size * x;
	offset_top = data->map.offs.y + data->map.c_size * y;
	mlx_put_image_to_window(data->mlx, data->win, img, offset_left, offset_top);
}

/* unsigned int	convert_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
} */

void	*make_square(int color, t_mlx_data *data)
{
	void			*img;
	unsigned int	*pixels;
	int				dummy;
	int				index;

	index = data->map.c_size * data->map.c_size - 1;
	img = mlx_new_image(data->mlx, data->map.c_size, data->map.c_size);
	pixels = (unsigned int *)mlx_get_data_addr(img, &dummy, &dummy, &dummy);
	while (index >= 0)
	{
		pixels[index] = color;
		index--;
	}
	return (img);
}

void	asign_basic_colors(t_mlx_data *data)
{
	data->wall = make_square(C_GREY, data);
	data->door = make_square(C_CRIMSON, data);
	data->empty = make_square(C_GREEN, data);
	data->player = make_square(C_VIOLET, data);
	data->coll = make_square(C_GOLD, data);
}
