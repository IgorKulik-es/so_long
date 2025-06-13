/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/13 20:11:06 by ikulik           ###   ########.fr       */
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
# define MAP_ERROR 2
# define WALL '1'
# define EMPTY '0'
# define COLLECT 'C'
# define DOOR 'E'
# define PLAYER 'P'
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DF_CELL 300

typedef struct s_coordinates
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_list
{
	char			*line;
	t_pos			pos;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

typedef struct s_map_data
{
	int		width;
	int		height;
	int		num_cols;
	int		c_size;
	char	**map;
	char	**map_copy;
	t_list	*read_lst;
	t_list	*cols;
	t_pos	player;
	t_pos	door;
}			t_map_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img1;
}		t_mlx_data;

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s, t_map_data *map);
t_list	*lst_push_back(t_map_data *map, t_list **lst, char *line, t_pos *pos);
void	clean_exit(t_map_data *map, char *error, int exit_code);
char	*get_next_line(int fd);
void	lst_clear(t_list **lst, int mode);
int		close_window(int keycode, t_mlx_data *data);
void	array_clear(char **arr, int size);
void	initialize_map(t_map_data *map);
int		read_map(t_map_data *map, int argc, char **argv);
void	check_map_basics(t_map_data *map);
void	check_map_advanced(t_map_data *map);
void	register_collectables(t_map_data *map);
int		search_route(t_map_data *map, int x, int y);
void	create_grid(t_map_data *map, t_mlx_data *mlx);

#endif
