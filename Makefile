NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	srcs/main.c \
		srcs/mlx_set_up.c \
		srcs/parsing.c \
		srcs/utils.c \
		srcs/utils_2.c \
		srcs/utils_3.c \


INCLDIR = ./includes


OBJ = $(SRCS:.c=.o)

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME) $(OBJB)

re : fclean all

.PHONY: all clean fclean re