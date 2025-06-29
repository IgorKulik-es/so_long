/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:51:30 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:36:14 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	initialize_anim(t_mlx_data *data);

void	create_frames(t_mlx_data *data)
{
	initialize_anim(data);
	set_frames(data, data->anim.idle_left, FR_IDLE, REVERSE);
	set_frames(data, data->anim.idle_right, FR_IDLE, FORWARD);
	set_frames(data, data->anim.walk_left, FR_WALK, REVERSE);
	set_frames(data, data->anim.walk_right, FR_WALK, FORWARD);
	set_frames(data, data->anim.act_right, FR_ACT, FORWARD);
	set_frames(data, data->anim.act_left, FR_ACT, REVERSE);
	set_frames(data, data->enem_base.idle_left, EN_IDLE, REVERSE);
	set_frames(data, data->enem_base.idle_right, EN_IDLE, FORWARD);
	set_frames(data, data->enem_base.walk_left, EN_WALK, REVERSE);
	set_frames(data, data->enem_base.walk_right, EN_WALK, FORWARD);
	set_frames(data, data->enem_base.act_left, EN_ACT, REVERSE);
	set_frames(data, data->enem_base.act_right, EN_ACT, FORWARD);
	set_frames(data, data->txt_nums, 10, NUMBERS);
}

void	initialize_anim(t_mlx_data *data)
{
	int	dummy;

	data->anim.facing = 1;
	data->anim.idl_frame = 0;
	data->enemies = NULL;
	data->anim.pos = data->map.player;
	data->anim.time = 0;
	data->anim.moving = 0;
	data->anim.step = 0;
	data->anim.acting = 0;
	data->game_over = 0;
	data->anim.act_left[FR_ACT] = mlx_xpm_file_to_image(data->mlx,
			"./img/Player_act_left.xpm", &dummy, &dummy);
	data->txt_moves = mlx_xpm_file_to_image(data->mlx,
			"./img/Text_moves.xpm", &dummy, &dummy);
	data->txt_nums[10] = mlx_xpm_file_to_image(data->mlx,
			"./img/Text_numbers.xpm", &dummy, &dummy);
	data->txt_go = mlx_xpm_file_to_image(data->mlx,
			"./img/Text_game_over.xpm", &dummy, &dummy);
	data->txt_win = mlx_xpm_file_to_image(data->mlx,
			"./img/Text_victory.xpm", &dummy, &dummy);
}

void	set_frames(t_mlx_data *data, void **anims, int num_frames, int mode)
{
	int	frame_curr;
	int	width;

	width = num_frames * AN_HEIGHT;
	frame_curr = 0;
	while (frame_curr < num_frames)
	{
		if (mode == FORWARD)
			anims[frame_curr] = stretch_anim(data, anims[num_frames], width,
					AN_HEIGHT * frame_curr);
		else if (mode == REVERSE)
			anims[num_frames - 1 - frame_curr] = stretch_anim(data,
					anims[num_frames], width, AN_HEIGHT * frame_curr);
		else if (mode == CLEAN)
			mlx_destroy_image(data->mlx, anims[frame_curr]);
		else if (mode == NUMBERS)
			anims[frame_curr] = stretch_banners(data, NUM_WIDTH * frame_curr);
		frame_curr++;
	}
	if (mode == CLEAN)
		mlx_destroy_image(data->mlx, anims[num_frames]);
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
	data->enem_base.idle_right[EN_IDLE] = mlx_xpm_file_to_image(data->mlx,
			"./img/Gob_idle_right.xpm", &dummy, &dummy);
	data->enem_base.idle_left[EN_IDLE] = mlx_xpm_file_to_image(data->mlx,
			"./img/Gob_idle_left.xpm", &dummy, &dummy);
	data->enem_base.walk_right[EN_WALK] = mlx_xpm_file_to_image(data->mlx,
			"./img/Gob_walk_right.xpm", &dummy, &dummy);
	data->enem_base.walk_left[EN_WALK] = mlx_xpm_file_to_image(data->mlx,
			"./img/Gob_walk_left.xpm", &dummy, &dummy);
	data->enem_base.act_right[EN_ACT] = mlx_xpm_file_to_image(data->mlx,
			"./img/Gob_act_right.xpm", &dummy, &dummy);
	data->enem_base.act_left[EN_ACT] = mlx_xpm_file_to_image(data->mlx,
			"./img/Gob_act_left.xpm", &dummy, &dummy);
	data->anim.act_right[FR_ACT] = mlx_xpm_file_to_image(data->mlx,
			"./img/Player_act_right.xpm", &dummy, &dummy);
}
