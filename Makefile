NAME = so_long
BONUSNAME = so_long_bonus
#TNAME = test
LIBRARY = lib_so_long.a
BLIBRARY = lib_so_long_bonus.a

SRCS = so_long_main.c
BONUSSRCS =

HEADER = so_long.h ./mlx/mlx.h
BONUSHEADER = so_long_bonus.h

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx
MFLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)
bonus: $(BONUSNAME)


$(BONUSNAME): $(BLIBRARY)
	cc -o $(NAME) $(BLIBRARY) -g

$(NAME): $(LIBRARY)
	cc $(OBJS) $(LIBRARY) $(MFLAGS) -o $(NAME)

$(LIBRARY): $(OBJS)
	ar -rcs -o $(LIBRARY) $(OBJS) $(HEADER)

$(BLIBRARY): $(BONUSOBJS)
	ar -rcs -o $(BLIBRARY) $(BONUSOBJS) $(BONUSHEADER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME) $(LIBRARY) $(BLIBRARY)

re: fclean all
