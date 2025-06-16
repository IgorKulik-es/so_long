/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:48:19 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/16 19:59:34 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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
	//data->empty = make_square(C_GREEN, data);
	//data->player = make_square(C_VIOLET, data);
	//data->coll = make_square(C_GOLD, data);
}

void	*stretch_to_fit(t_mlx_data *data, void *src, int height, int width)
{
	void			*img;
	double			factor;
	unsigned int	*pixels[2];
	int				i;
	int				j;

	i = 0;
	factor = (double)data->map.c_size / (double)height;
	img = mlx_new_image(data->mlx, data->map.c_size, data->map.c_size);
	pixels[0] = (unsigned int *)mlx_get_data_addr(img, &i, &i, &i);
	pixels[1] = (unsigned int *)mlx_get_data_addr(src, &i, &i, &i);
	while (i < data->map.c_size)
	{
		j = 0;
		while (j < data->map.c_size)
		{
			pixels[0][i * data->map.c_size + j] = pixels[1][((int)((double)i
						/ factor)) * width + (int)((double)j / factor)];
			j++;
		}
		i++;
	}
	//mlx_destroy_image(data->mlx, src);
	return (img);
}
