.PHONY: all clean fclean re

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

NAME = pipex
SRC_DIR = srcs
OBJ_DIR = objs
HEADER = headers/pipex.h

RM = rm -f

SRC_FILES = pipex.c\
			utils/split.c\
			utils/libft.c\
			utils/ft_check_comands_utils.c\
			ft_check_argc.c\
			ft_check_comands.c\
			ft_check_fds.c\
			ft_close.c\
			ft_parse_comands.c\
			utils/ft_split_space.c\
			utils/ft_split_space_utils.c\
			ft_create_pipes.c\
			ft_process.c\
			ft_free.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:
	@make fclean && make all

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)/utils
