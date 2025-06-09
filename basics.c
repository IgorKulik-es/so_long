/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:09:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/07 20:09:10 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	index;

	diff = 0;
	index = 0;
	while (*s1 && *s2 && index < n)
	{
		if (*s1 != *s2)
		{
			diff = (unsigned char)*s1 - (unsigned char)*s2;
			return (diff);
		}
		s1++;
		s2++;
		index++;
	}
	if (index < n)
		diff = (unsigned char)*s1 - (unsigned char)*s2;
	return (diff);
}

t_list	*lst_push_back(t_map_data *map, char *line)
{
	t_list	*new;
	t_list	*iter;

	if (map->read_lst == NULL)
		return (NULL);
	iter = map->read_lst;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		clean_exit(map, "so_long: malloc: c function failure", 1);
	new->line = line;
	new->next = NULL;
	if (iter != NULL)
	{
		while(iter->next != NULL)
			iter = iter->next;
		new->prev = iter;
		iter->next = new;
	}
	else
	{
		new->prev = NULL;
		map->read_lst = new;
	}
	return (map->read_lst);
}
