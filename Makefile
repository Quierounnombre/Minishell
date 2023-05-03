NAME = minishell
LIBFT = libft_def/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
RM = rm -f

BLACK = \033[0;30m
RED =   \033[0;31m
GREEN = \033[0;32m
YELLOW =    \033[0;33m
BLUE  = \033[0;34m
MAGENTA =   \033[0;35m
CYAN =  \033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

FILE_MAIN = ./srcs/main.c
OBJ_MAIN = ./srcs/main.o

FILES_CMD = await_cmd \

PARSE_CMD = ./srcs/cmd/
SRCS_CMD = $(addprefix $(PARSE_CMD), $(addsuffix .c, $(FILES_CMD)))
OBJS_CMD = $(addprefix $(PARSE_CMD), $(addsuffix .o, $(FILES_CMD)))

OBJS = $(OBJS_CMD) $(OBJ_MAIN)
SRCS = $(SRCS_CMD) $(FILE_MAIN)

all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(LBLUE)\n$(NAME) compilado con éxito\n$(RESET)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C ./libft_def
	echo "$(YELLOW)\nArchivos .o $(NAME) eliminados\n$(RESET)"

fclean:
	@$(RM) $(OBJS)
	echo "$(YELLOW)\nArchivos .o $(NAME) eliminados\n$(RESET)"
	@$(MAKE) fclean -C ./libft_def
	@$(RM) $(NAME) $(MLX42)
	echo "$(RED)\n$(NAME) eliminado\n$(RESET)"


re: fclean libft $(NAME)

libft:
	@$(MAKE) -C ./libft_def

.PHONY: all clean fclean re libft
.SILENT: