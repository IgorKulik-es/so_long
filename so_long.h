/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/12 20:09:18 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"

# define TOTAL 1
# define PARTIAL 0
# define WALL '1'
# define EMPTY '0'
# define COLLECT 'C'
# define M_EXIT 'E'
# define PLAYER 'P'

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

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
}		t_mlx_data;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*lst_push_back(t_map_data *map, char *line);
void	clean_exit(t_map_data *map, char *error, int exit_code);
char	*get_next_line(int fd);
void	lst_clear(t_list **lst, int mode);
int		close_window(int keycode, t_mlx_data *data);
void	array_clear(char **arr, int size);

#endif
