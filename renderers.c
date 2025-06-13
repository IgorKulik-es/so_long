/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:48:19 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/13 20:24:09 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_grid(t_map_data *map, t_mlx_data *mlx)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img1, pos.x * map->c_size, pos.y * map->c_size);
			(pos.x)++;
		}
		(pos.y)++;
	}
}
