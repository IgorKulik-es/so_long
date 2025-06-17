/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:51:30 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/17 20:06:09 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_frames(t_mlx_data *data)
{
	int		frame;

	frame = -1;
	data->anim.facing = 1;
	while (++frame < FR_IDLE)
		data->anim.idle_left[FR_IDLE - 1 - frame] = stretch_anim(data, data
				->anim.idle_left[FR_IDLE], AN_IDLE_W, AN_HEIGHT * frame);
	mlx_destroy_image(data->mlx, data->anim.idle_left[FR_IDLE]);
	while (--frame >= 0)
		data->anim.idle_right[frame] = stretch_anim(data, data
				->anim.idle_right[FR_IDLE], AN_IDLE_W, AN_HEIGHT * frame);
	mlx_destroy_image(data->mlx, data->anim.idle_right[FR_IDLE]);
	while (++frame < FR_WALK)
		data->anim.walk_left[FR_WALK - 1 - frame] = stretch_anim(data, data
				->anim.walk_left[FR_WALK], AN_WALK_W, AN_WALK_W * frame);
	mlx_destroy_image(data->mlx, data->anim.walk_left[FR_WALK]);
	while (--frame >= 0)
		data->anim.walk_right[frame] = stretch_anim(data, data
				->anim.walk_right[FR_WALK], AN_WALK_W, AN_WALK_W * frame);
	mlx_destroy_image(data->mlx, data->anim.walk_right[FR_WALK]);
}

void	load_anim_src(t_mlx_data *data)
{
	int	dummy;

	data->anim.idle_left[FR_IDLE] = mlx_xpm_file_to_image(data->mlx,
			"./img/Idle_left.xpm", &dummy, &dummy);
	data->anim.idle_right[FR_IDLE] = mlx_xpm_file_to_image(data->mlx,
			"./img/Idle_right.xpm", &dummy, &dummy);
	data->anim.walk_left[FR_WALK] = mlx_xpm_file_to_image(data->mlx,
			"./img/Walk_left.xpm", &dummy, &dummy);
	data->anim.walk_right[FR_WALK] = mlx_xpm_file_to_image(data->mlx,
			"./img/Walk_right.xpm", &dummy, &dummy);
}


void	clean_anim_stand(t_mlx_data *data)
{
	int	frame;

	frame = -1;
	while (++frame < FR_IDLE)
		mlx_destroy_image(data->mlx, data->anim.idle_left[frame]);
	while (--frame >= 0)
		mlx_destroy_image(data->mlx, data->anim.idle_right[frame]);
	while (++frame < FR_WALK)
		mlx_destroy_image(data->mlx, data->anim.walk_left[frame]);
	while (--frame >= 0)
		mlx_destroy_image(data->mlx, data->anim.walk_right[frame]);
}
