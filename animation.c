/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:15:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/18 16:58:42 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	idle_entity(t_mlx_data *data, t_anim *entity, int num_frames)
{
	struct timeval			time_curr;

	gettimeofday(&time_curr, NULL);
	if ((__uint64_t)time_curr.tv_usec - entity->time > AN_DELAY)
	{
		if (entity->facing == 1)
			put_image_to_grid(data, entity->idle_right[entity->idl_frame],
				entity->pos.x, entity->pos.y);
		else
			put_image_to_grid(data, entity->idle_left[entity->idl_frame],
				entity->pos.x, entity->pos.y);
		(entity->idl_frame)++;
		if (entity->idl_frame >= num_frames)
			entity->idl_frame = 0;
		entity->time = (__uint64_t)time_curr.tv_usec;
	}
	return (0);
}

int	idle_all(t_mlx_data *data)
{
	int	index;

	index = 0;
	idle_entity(data, &(data->anim), FR_IDLE);
	while (index < data->map.num_enem)
		idle_entity(data, &(data->enemies[0]), EN_IDLE);
	return (0);
}

void	move_entity(t_mlx_data *data, t_anim *entity, int num_fr)
{
	__uint64_t	step;
}
