/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:05 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/19 14:17:35 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->door);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->empty);
	mlx_destroy_image(data->mlx, data->coll);
	clean_anims(data);
	if (data->enemies)
		free(data->enemies);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_exit(&(data->map), "OK", 0);
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
