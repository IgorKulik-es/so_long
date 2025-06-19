/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:15:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/19 20:28:21 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_midway(t_mlx_data *data, t_anim *anim, int num_fr);
void	move_entity(t_mlx_data *data, t_anim *entity, int num_fr);

int	idle_entity(t_mlx_data *data, t_anim *entity, int num_frames)
{
	struct timeval			time_curr;

	gettimeofday(&time_curr, NULL);
	if (((__uint64_t)time_curr.tv_usec - entity->time > AN_DELAY)
		&& entity->moving == 0 && entity->acting == 0)
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
	{
		idle_entity(data, &(data->enemies[index]), EN_IDLE);
		index++;
	}
	move_entity(data, &(data->anim), FR_WALK);
	while (--index >= 0)
		move_entity(data, &(data->enemies[index]), EN_WALK);
	animate_act(data, &(data->anim), FR_ACT, AN_DEATH);
	while (index < data->map.num_enem)
	{
		animate_act(data, &(data->enemies[index]), EN_ACT, AN_ATTACK);
	}
	if (data->game_over == 1 && data->anim.acting == 0)
		close_window(data);
	return (0);
}

void	move_entity(t_mlx_data *data, t_anim *entity, int num_fr)
{
	struct timeval	time_c;
	size_t			interval;

	if (entity->moving == 0)
		return ;
	gettimeofday(&time_c, NULL);
	interval = 0;
	if (num_fr != 0)
		interval = ((size_t)AN_WALK / (size_t)num_fr) * (size_t)entity->step;
	if (entity->step == 0)
		entity->time = (size_t)time_c.tv_sec * 1000000 + (size_t)time_c.tv_usec;
	if ((size_t)time_c.tv_sec * (size_t)1000000 + (size_t)time_c.tv_usec
		- entity->time >= interval)
	{
		put_image_midway(data, entity, num_fr);
		(entity->step)++;
	}
	if (entity->step >= num_fr)
	{
		entity->moving = 0;
		entity->step = 0;
		entity->idl_frame = 0;
		put_image_to_grid(data, data->empty, entity->pos.x, entity->pos.y);
		entity->pos = entity->dest;
	}
}

void	put_image_midway(t_mlx_data *data, t_anim *anim, int num_fr)
{
	t_pos	new;
	t_pos	old;

	new.x = data->map.offs.x + data->map.c_size * anim->dest.x;
	new.y = data->map.offs.y + (data->map.c_size) * anim->dest.y;
	old.x = data->map.offs.x + data->map.c_size * anim->pos.x;
	old.y = data->map.offs.y + data->map.c_size * anim->pos.y;
	new.x = ((num_fr - anim->step + 1) * old.x
			+ (anim->step + 1) * new.x) / (num_fr + 2);
	new.y = ((num_fr - anim->step + 1) * old.y
			+ (anim->step + 1) * new.y) / (num_fr + 2);
	put_image_to_grid(data, data->empty, anim->pos.x, anim->pos.y);
	put_image_to_grid(data, data->empty, anim->dest.x, anim->dest.y);
	if (anim->facing == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			anim->walk_right[anim->step], new.x, new.y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			anim->walk_left[anim->step], new.x, new.y);
}

void	animate_act(t_mlx_data *data, t_anim *entity, int num_fr, size_t speed)
{
	struct timeval	time_c;

	if (entity->acting == 0 || data->anim.moving == 1)
		return ;
	gettimeofday(&time_c, NULL);
	if (entity->step == 0)
		entity->time = (size_t)time_c.tv_sec * 1000000 + (size_t)time_c.tv_usec;
	if ((size_t)time_c.tv_sec * (size_t)1000000 + (size_t)time_c.tv_usec
		- entity->time >= speed * entity->step)
	{
		if (entity->facing == 1)
			put_image_to_grid(data, entity->act_right[entity->step],
				entity->pos.x, entity->pos.y);
		else
			put_image_to_grid(data, entity->act_left[entity->step],
				entity->pos.x, entity->pos.y);
		(entity->step)++;
	}
	if (entity->step >= num_fr)
	{
		entity->acting = 0;
		entity->step = 0;
	}
}
