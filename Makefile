NAME = so_long
BONUSNAME = so_long_bonus
LIBRARY = minilibx-linux/libmlx_Linux.a
LIBGIT = https://github.com/42paris/minilibx-linux.git

SRC = so_long_main.c gaming.c map_checks.c get_next_line.c get_next_line_utils.c\
cleaners.c basics1.c basics2.c initializer.c renderers.c
BONUSSRC = so_long_main_bonus.c gaming.c map_checks.c get_next_line.c get_next_line_utils.c\
cleaners_bonus.c basics1.c basics2.c initializer.c renderers.c frame_initializer.c\
animation.c animation2.c enemies_bonus.c gaming_bonus.c renderers_bonus.c

SRCSDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCSDIR)/, $(SRC))
BONUSSRCS = $(addprefix $(OBJDIR)/, $(BONUSSRC))

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
BONUSOBJS = $(addprefix $(OBJDIR)/,  $(notdir $(BONUSSRCS:.c=.o)))

CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -I./minilibx-linux
MFLAGS = -L./minilibx-linux -L/usr/lib -I./minilibx-linux -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)
bonus: $(BONUSNAME)

$(NAME): $(LIBRARY) $(OBJS)
	cc $(OBJS) $(LIBRARY) $(MFLAGS) -o $(NAME)

$(BONUSNAME): $(BONUSOBJS) $(LIBRARY)
	cc $(BONUSOBJS) $(LIBRARY) $(MFLAGS) -o $(BONUSNAME)

$(LIBRARY):
	git clone $(LIBGIT) minilibx-linux
	cd minilibx-linux && ./configure

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME) $(BONUSNAME)

re: fclean all
