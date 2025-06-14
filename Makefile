NAME = so_long
BONUSNAME = so_long_bonus
#TNAME = test
LIBRARY = minilibx-linux/libmlx_Linux.a
BLIBRARY = lib_so_long_bonus.a

SRCS = so_long_main.c window_functions.c map_check.c get_next_line.c get_next_line_utils.c\
cleaners.c basics.c initializer.c renderers.c
BONUSSRCS =
TSRC = map_check.c get_next_line.c get_next_line_utils.c cleaners.c basics.c initializer.c\
parse_main.c

HEADER = so_long.h ./minilibx-linux/mlx.h
BONUSHEADER = so_long_bonus.h

OBJS = $(SRCS:.c=.o)
TOBJS = $(TSRC:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-I/usr/include -I./minilibx-linux
MFLAGS = -L./minilibx-linux -L/usr/lib -I./minilibx-linux -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)
parse: test
bonus: $(BONUSNAME)

test: $(TOBJS)
	cc $(TOBJS) -o test

$(NAME): $(OBJS)
	cc $(OBJS) $(LIBRARY) $(MFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME) $(LIBRARY) $(BLIBRARY)

re: fclean all
