NAME = so_long
BONUSNAME = so_long_bonus
#TNAME = test
LIBRARY = lib_so_long.a
BLIBRARY = lib_so_long_bonus.a

SRCS = so_long_main.c window_functions.c
BONUSSRCS =

HEADER = so_long.h ./minilibx-linux/mlx.h
BONUSHEADER = so_long_bonus.h

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux
MFLAGS = -Lminilibx-linux -lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)
bonus: $(BONUSNAME)


$(BONUSNAME): $(BLIBRARY)
	cc -o $(NAME) $(BLIBRARY) -g

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME) $(MFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME) $(LIBRARY) $(BLIBRARY)

re: fclean all
