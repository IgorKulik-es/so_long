/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:05 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/12 18:25:30 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
