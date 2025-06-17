/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:48:19 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/17 19:13:21 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_grid(t_mlx_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < data->map.height)
	{
		pos.x = 0;
		while (pos.x < data->map.width)
		{
			if (data->map.map[pos.y][pos.x] == WALL)
				put_image_to_grid(data, data->wall, pos.x, pos.y);
			if (data->map.map[pos.y][pos.x] == EMPTY)
				put_image_to_grid(data, data->empty, pos.x, pos.y);
			if (data->map.map[pos.y][pos.x] == COLLECT)
				put_image_to_grid(data, data->coll, pos.x, pos.y);
			if (data->map.map[pos.y][pos.x] == DOOR)
				put_image_to_grid(data, data->door, pos.x, pos.y);
			if (data->map.map[pos.y][pos.x] == PLAYER)
				put_image_to_grid(data, data->player, pos.x, pos.y);
			(pos.x)++;
		}
		(pos.y)++;
	}
}

void	put_image_to_grid(t_mlx_data *data, void *img, int x, int y)
{
	int		offset_left;
	int		offset_top;

	offset_left = data->map.offs.x + data->map.c_size * x;
	offset_top = data->map.offs.y + (data->map.c_size - 1) * y;
	mlx_put_image_to_window(data->mlx, data->win, img, offset_left, offset_top);
}

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

void	*stretch_to_fit(t_mlx_data *data, void *src, int width, int start)
{
	void			*img;
	double			factor;
	unsigned int	*pixels[2];
	int				i;
	int				j;

	i = 0;
	factor = (double)data->map.c_size / (double)DF_CELL;
	img = mlx_new_image(data->mlx, data->map.c_size, data->map.c_size);
	pixels[0] = (unsigned int *)mlx_get_data_addr(img, &i, &i, &i);
	pixels[1] = (unsigned int *)mlx_get_data_addr(src, &i, &i, &i);
	while (i < data->map.c_size)
	{
		j = 0;
		while (j < data->map.c_size)
		{
			pixels[0][i * data->map.c_size + j] = pixels[1][((int)((double)i
						/ factor)) * width + (int)((double)j / factor) + start];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, src);
	return (img);
}

void	*stretch_anim(t_mlx_data *data, void *src, int width, int start)
{
	void			*img;
	double			factor;
	unsigned int	*pixels[2];
	int				i;
	int				j;

	i = 0;
	factor = (double)data->map.c_size / (double)AN_HEIGHT;
	img = mlx_new_image(data->mlx, data->map.c_size, data->map.c_size);
	pixels[0] = (unsigned int *)mlx_get_data_addr(img, &i, &i, &i);
	pixels[1] = (unsigned int *)mlx_get_data_addr(src, &i, &i, &i);
	while (i < data->map.c_size)
	{
		j = 0;
		while (j < data->map.c_size)
		{
			pixels[0][i * data->map.c_size + j] = pixels[1][((int)((double)i
						/ factor)) * width + (int)((double)j / factor) + start];
			j++;
		}
		i++;
	}
	return (img);
}
