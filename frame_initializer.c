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

#include "so_long_bonus.h"

void	create_anim_stand(t_mlx_data *data)
{
	int		frame;

	frame = 0;
	while (frame < N_FRAMES_STAND)
	{
		data->anim.standing[frame] = stretch_to_fit(data,
				data->anim.standing[N_FRAMES_STAND], ANIM_FRAME_HEIGHT,
				ANIM_STAND_WIDTH);
		frame++;
	}
}

void	clean_anim_stand(t_mlx_data *data)
{
	int	frame;

	frame = 0;
	while (frame <= N_FRAMES_STAND)
	{
		if (data->anim.standing[frame])
			mlx_destroy_image(data->mlx, data->anim.standing[frame]);
	}
}
