CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
# MFLAGS = -lmlx -framework AppKit -framework OpenGL
# MFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm
SRC = free.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/main.c parsing/pars_map.c parsing/tools.c parsing/tools2.c
OBJ = $(SRC:.c=.o)
NAME = cub3D
all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o:%.c parsing/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :

	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# NAME = cub3D

# PARSER_SRC = parsing/main.c
# SRC   = $(PARSER_SRC) free.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/pars_map.c parsing/tools.c parsing/tools2.c

# OBJS = $(SRC:.c=.o)
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g \
#          -IParssing \
# 		 -Iminilibx-linux

# MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# all: $(NAME)

# $(NAME): $(OBJS) cub3d.h
# 	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# NAME = cub3D

# SRC = parsing/main.c free.c parsing/get_next_line.c parsing/get_next_line_utils.c \
#       parsing/pars_map.c parsing/tools.c parsing/tools2.c

# OBJS = $(SRC:.c=.o)
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g \
#          -Iparsing \
#          -Iminilibx-linux

# MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

# all: $(NAME)

# $(NAME): $(OBJS) cub3d.h
# 	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all



