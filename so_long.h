/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/11 14:54:54 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

# define TOTAL 1
# define PARTIAL 0

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

typedef struct s_map_data
{
	int		width;
	int		height;
	char	**map;
	t_list	*read_lst;
}			t_map_data;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*lst_push_back(t_map_data *map, char *line);
void	clean_exit(char *error, t_map_data *map, int exit_code);
char	*get_next_line(int fd);


#endif
