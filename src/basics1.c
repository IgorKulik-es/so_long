/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:09:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:39:08 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	length;

	length = 0;
	index = 0;
	while (src[length])
		length++;
	if (size > 0)
	{
		while (src[index] && (index < size - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (length);
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

char	*ft_strdup(const char *s, t_map_data *map)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		clean_exit(map, "malloc failure", EXIT_FAILURE);
	while (i < len)
	{
		result[i] = (char)s[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

t_list	*lst_push_back(t_map_data *map, t_list **lst, char *line, t_pos *pos)
{
	t_list	*new;
	t_list	*iter;

	iter = *lst;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		clean_exit(map, "so_long: malloc: c function failure", 1);
	new->line = line;
	if (pos)
		new->pos = *pos;
	new->next = NULL;
	if (iter != NULL)
	{
		while (iter->next != NULL)
			iter = iter->next;
		new->prev = iter;
		iter->next = new;
	}
	else
	{
		new->prev = NULL;
		*lst = new;
	}
	return (*lst);
}
