/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/18 16:42:37 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "./minilibx-linux/mlx.h"

# define TOTAL 1
# define PARTIAL 0
# define MAP_ERROR 2
# define WALL '1'
# define EMPTY '0'
# define COLLECT 'C'
# define DOOR 'E'
# define PLAYER 'P'
# define ENEMY 'S'
# define UP 'w'
# define DOWN 's'
# define LEFT 'a'
# define RIGHT 'd'
# define ESC 65307
# define ESC_ASCII 33
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440
# define DF_CELL 32
# define TOP_OFF 100
# define SIDE_OFF 100
# define C_GOLD 16761104
# define C_GREEN 8439808
# define C_VIOLET 9055202
# define C_CRIMSON 14423100
# define C_GREY 3100495
# define AN_HEIGHT 38
# define AN_IDLE_W 266
# define AN_WALK_W 304
# define AN_DELAY 130000
# define FR_IDLE 7
# define FR_WALK 8
# define EN_IDLE 4
# define EN_WALK 8
# define EN_ACT 4
# define EN_DENSITY 10
# define FORWARD 1
# define REVERSE 0
# define CLEAN 2

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
	int		num_empty;
	int		num_enem;
	int		c_size;
	int		moves;
	char	**map;
	char	**map_copy;
	t_list	*read_lst;
	t_list	*cols;
	t_pos	player;
	t_pos	door;
	t_pos	offs;
}			t_map_data;
typedef struct s_anim_imgs
{
	void		*idle_left[FR_IDLE + 1];
	void		*idle_right[FR_IDLE + 1];
	void		*walk_left[FR_WALK + 1];
	void		*walk_right[FR_WALK + 1];
	void		*act_left[EN_ACT + 1];
	void		*act_right[EN_ACT + 1];
	t_pos		pos;
	__uint64_t	time;
	int			moves;
	int			facing;
	int			idl_frame;
}		t_anim;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*wall;
	void		*empty;
	void		*coll;
	void		*door;
	void		*player;
	t_anim		anim;
	t_anim		enem_base;
	t_anim		*enemies;
	t_map_data	map;
}		t_mlx_data;

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *s, t_map_data *map);
t_list	*lst_push_back(t_map_data *map, t_list **lst, char *line, t_pos *pos);
void	clean_exit(t_map_data *map, char *error, int exit_code);
char	*get_next_line(int fd);
void	lst_clear(t_list **lst, int mode);
int		key_manager(int key, t_mlx_data *data);
void	close_window(t_mlx_data *data);
void	array_clear(char **arr, int size);
void	initialize_map(t_map_data *map);
void	add_images(t_mlx_data *data);
int		read_map(t_map_data *map, int argc, char **argv);
void	check_map_basics(t_map_data *map);
void	check_map_advanced(t_map_data *map);
void	register_collectables(t_map_data *map);
int		search_route(t_map_data *map, int x, int y);
void	validate_map(t_map_data *map, int argc, char **argv);
void	create_grid(t_mlx_data *mlx);
void	asign_basic_colors(t_mlx_data *data);
void	put_image_to_grid(t_mlx_data *data, void *img, int x, int y);
void	*stretch_to_fit(t_mlx_data *data, void *src, int width, int start);
void	*stretch_anim(t_mlx_data *data, void *src, int width, int start);
void	clean_anims(t_mlx_data *data);
void	load_anim_src(t_mlx_data *data);
void	create_frames(t_mlx_data *data);
int		idle_all(t_mlx_data *data);
void	spawn_enemies(t_mlx_data *data, t_map_data *map);
void	initialize_enemies(t_mlx_data *data);

#endif
