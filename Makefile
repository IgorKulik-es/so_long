NAME = so_long
BONUSNAME = so_long_bonus
#TNAME = test
LIBRARY = minilibx-linux/libmlx_Linux.a
BLIBRARY = lib_so_long_bonus.a

SRCS = so_long_main.c gaming.c map_checks.c get_next_line.c get_next_line_utils.c\
cleaners.c basics1.c basics2.c initializer.c renderers.c
BONUSSRCS = so_long_main_bonus.c gaming.c map_checks.c get_next_line.c get_next_line_utils.c\
cleaners_bonus.c basics1.c basics2.c initializer_bonus.c renderers.c frame_initializer.c\
animation.c


HEADER = so_long.h ./minilibx-linux/mlx.h
BONUSHEADER = so_long_bonus.h

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g #-I/usr/include -I./minilibx-linux
MFLAGS = -L./minilibx-linux -L/usr/lib -I./minilibx-linux -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)
bonus: $(BONUSNAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(LIBRARY) $(MFLAGS) -o $(NAME)

$(BONUSNAME): $(BONUSOBJS)
	cc $(BONUSOBJS) $(LIBRARY) $(MFLAGS) -o $(BONUSNAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME) $(BONUSNAME)

re: fclean all
