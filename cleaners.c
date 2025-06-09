/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:05 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/09 11:12:05 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit(t_map_data *map, char *error, int exit_code)
{
	write(2, "so_long: ", 9);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	lst_clear(&(map->read_lst), TOTAL);
	exit(exit_code);
}

void	lst_clear(t_list **lst, int mode)
{
	t_list	*iter;
	t_list	*cleaner;

	if (lst == NULL)
		return ;
	iter = *lst;
	while (iter)
	{
		cleaner = iter;
		iter = iter->next;
		if (cleaner->line && mode == TOTAL)
			free(cleaner->line);
		free(cleaner);
	}
	*lst = NULL;
}