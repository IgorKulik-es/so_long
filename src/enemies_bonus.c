/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:10:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:36:09 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	copy_links(void **dst, void **src, int count);

void	spawn_enemies(t_mlx_data *data, t_map_data *map)
{
	int		count;
	t_pos	pos;
	int		spawn;

	count = map->num_enem;
	while (--count >= 0)
	{
		spawn = rand() % (map->num_empty) + 1;
		pos.y = 0;
		while ((++(pos.y) < (map->height - 1)) && spawn > 0)
		{
			pos.x = 0;
			while ((++(pos.x) < (map->width - 1)) && (spawn > 0))
			{
				if (map->map[pos.y][pos.x] == EMPTY)
					spawn--;
				if (spawn == 0 && map->map[pos.y][pos.x] == EMPTY)
				{
					map->map[pos.y][pos.x] = ENEMY;
					(map->num_empty)--;
					data->enemies[count].pos = pos;
				}
			}
		}
	}
}

void	initialize_enem_base(t_mlx_data *data)
{
	(data->enem_base).time = 0;
	(data->enem_base).idl_frame = 0;
	(data->enem_base).facing = 1;
	(data->enem_base).moving = 0;
	(data->enem_base).step = 0;
	(data->enem_base).acting = 0;
	(data->enem_base).pos.x = 0;
	(data->enem_base).pos.y = 0;
}

void	initialize_enemies(t_mlx_data *data)
{
	int	index;

	index = -1;
	initialize_enem_base(data);
	data->map.num_enem = data->map.num_empty / EN_DENSITY;
	data->enemies = malloc(data->map.num_enem * sizeof(t_anim));
	while (++index < data->map.num_enem)
	{
		data->enemies[index] = data->enem_base;
		copy_links((data->enemies[index]).idle_left,
			data->enem_base.idle_left, EN_IDLE);
		copy_links((data->enemies[index]).idle_right,
			data->enem_base.idle_right, EN_IDLE);
		copy_links((data->enemies[index]).walk_left,
			data->enem_base.walk_left, EN_WALK);
		copy_links((data->enemies[index]).walk_right,
			data->enem_base.walk_right, EN_WALK);
	}
}

void	copy_links(void **dst, void **src, int count)
{
	while (count > 0)
	{
		count--;
		dst[count] = src[count];
	}
}

t_anim	*find_enemy(t_mlx_data *data, t_pos find)
{
	int	index;

	index = 0;
	while (index < data->map.num_enem)
	{
		if ((data->enemies[index]).pos.x == find.x
			&& (data->enemies[index]).pos.y == find.y)
			return (&(data->enemies[index]));
		index++;
	}
	return (NULL);
}
