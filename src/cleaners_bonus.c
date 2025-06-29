/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:05 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:45:31 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	close_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->door);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->wall_d);
	mlx_destroy_image(data->mlx, data->empty);
	mlx_destroy_image(data->mlx, data->coll);
	mlx_destroy_image(data->mlx, data->txt_go);
	mlx_destroy_image(data->mlx, data->txt_moves);
	mlx_destroy_image(data->mlx, data->txt_win);
	clean_anims(data);
	if (data->enemies)
		free(data->enemies);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_exit(&(data->map), "OK", 0);
	return (0);
}

void	clean_exit(t_map_data *map, char *error, int exit_code)
{
	if (exit_code != 0)
	{
		if (exit_code == EXIT_FAILURE)
			write(2, "so_long: ", 9);
		if (exit_code == MAP_ERROR)
			write(2, "Error\n", 6);
		if (error)
			write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
	lst_clear(&(map->read_lst), TOTAL);
	lst_clear(&(map->cols), PARTIAL);
	if (map->map)
		free(map->map);
	array_clear(map->map_copy, map->height);
	exit(exit_code);
}

void	lst_clear(t_list **lst, int mode)
{
	t_list	*iter;
	t_list	*cleaner;

	if (lst == NULL || *lst == NULL)
		return ;
	iter = *lst;
	while (iter)
	{
		cleaner = iter;
		iter = iter->next;
		if (mode == TOTAL && cleaner->line)
			free(cleaner->line);
		free(cleaner);
	}
	*lst = NULL;
}

void	array_clear(char **arr, int size)
{
	int	index;

	index = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while (index < size)
	{
		if (arr[index])
			free(arr[index]);
		index++;
	}
	free(arr);
}

void	clean_anims(t_mlx_data *data)
{
	set_frames(data, data->anim.idle_left, FR_IDLE, CLEAN);
	set_frames(data, data->anim.idle_right, FR_IDLE, CLEAN);
	set_frames(data, data->anim.walk_left, FR_WALK, CLEAN);
	set_frames(data, data->anim.walk_right, FR_WALK, CLEAN);
	set_frames(data, data->anim.act_left, FR_ACT, CLEAN);
	set_frames(data, data->anim.act_right, FR_ACT, CLEAN);
	set_frames(data, data->enem_base.idle_left, EN_IDLE, CLEAN);
	set_frames(data, data->enem_base.idle_right, EN_IDLE, CLEAN);
	set_frames(data, data->enem_base.walk_left, EN_WALK, CLEAN);
	set_frames(data, data->enem_base.walk_right, EN_WALK, CLEAN);
	set_frames(data, data->enem_base.act_left, EN_ACT, CLEAN);
	set_frames(data, data->enem_base.act_right, EN_ACT, CLEAN);
	set_frames(data, data->txt_nums, 10, CLEAN);
}
