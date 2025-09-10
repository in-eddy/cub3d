CC = cc 
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework AppKit -framework OpenGL
SRC = free.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/main.c parsing/pars_map.c parsing/tools.c parsing/tools2.c
OBJ = $(SRC:.c=.o)
NAME = cub3D
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(MFLAGS) -o $(NAME)

%.o:%.c parsing/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :

	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
