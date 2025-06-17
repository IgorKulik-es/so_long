/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:51:30 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/16 19:49:33 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_frames(t_mlx_data *data)
{
	int		frame;

	frame = -1;
	while (++frame < N_FRAMES_IDLE)
		data->anim.idle_left[frame] = stretch_to_fit(data, data->
			anim.idle_left[N_FRAMES_IDLE], ANIM_IDLE_WIDTH, DF_CELL * frame);
	while (--frame >= 0)
		data->anim.idle_right[frame] = stretch_to_fit(data, data->
			anim.idle_right[N_FRAMES_IDLE], ANIM_IDLE_WIDTH, DF_CELL * frame);
	while (++frame < N_FRAMES_WALK)
		data->anim.walk_left[frame] = stretch_to_fit(data, data->
			anim.walk_left[N_FRAMES_WALK], ANIM_WALK_WIDTH, DF_CELL * frame);
	while (--frame >= 0)
		data->anim.walk_right[frame] = stretch_to_fit(data, data->
			anim.walk_right[N_FRAMES_WALK], ANIM_WALK_WIDTH, DF_CELL * frame);
	mlx_destroy_image(data->mlx, data->anim.idle_left[N_FRAMES_IDLE]);
	mlx_destroy_image(data->mlx, data->anim.idle_right[N_FRAMES_IDLE]);
	mlx_destroy_image(data->mlx, data->anim.walk_left[N_FRAMES_WALK]);
	mlx_destroy_image(data->mlx, data->anim.walk_right[N_FRAMES_WALK]);
}

void	clean_anim_stand(t_mlx_data *data)
{
	int	frame;

	frame = -1;
	while (++frame < N_FRAMES_IDLE)
		mlx_destroy_image(data->mlx, data->anim.idle_left[frame]);
	while (--frame >= 0)
		mlx_destroy_image(data->mlx, data->anim.idle_right[frame]);
	while (++frame < N_FRAMES_WALK)
		mlx_destroy_image(data->mlx, data->anim.walk_left[frame]);
	while (--frame >= 0)
		mlx_destroy_image(data->mlx, data->anim.walk_right[frame]);
}
