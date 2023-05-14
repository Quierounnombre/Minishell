NAME = minishell
LIBFT = libft_def/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBS_FLAGS = -lreadline
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
			cmd_manager \
			ft_pipe \

CMD_DIR = ./srcs/cmd/
SRCS_CMD = $(addprefix $(CMD_DIR), $(addsuffix .c, $(FILES_CMD)))
OBJS_CMD = $(addprefix $(CMD_DIR), $(addsuffix .o, $(FILES_CMD)))

FILES_UTILS = ft_cleanchild \
			ft_storechild \
			ft_cleancmd \

UTILS_DIR = ./srcs/utils/
SRCS_UTILS = $(addprefix $(UTILS_DIR), $(addsuffix .c, $(FILES_UTILS)))
OBJS_UTILS = $(addprefix $(UTILS_DIR), $(addsuffix .o, $(FILES_UTILS)))

FILES_ERRORMNG = ft_cleanshell \
				ft_error \

ERRORMNG_DIR = ./srcs/errormng/
SRCS_ERRORMNG = $(addprefix $(ERRORMNG_DIR), $(addsuffix .c, $(FILES_ERRORMNG)))
OBJS_ERRORMNG = $(addprefix $(ERRORMNG_DIR), $(addsuffix .o, $(FILES_ERRORMNG)))

FILES_START = init_shell_struct \
			start \

START_DIR = ./srcs/startup/
SRCS_START = $(addprefix $(START_DIR), $(addsuffix .c, $(FILES_START)))
OBJS_START = $(addprefix $(START_DIR), $(addsuffix .o, $(FILES_START)))

FILES_PROCESS = add_pid_to_lst \
				do_fork \

PROCESS_DIR = ./srcs/Process/
SRCS_PROCESS = $(addprefix $(PROCESS_DIR), $(addsuffix .c, $(FILES_PROCESS)))
OBJS_PROCESS = $(addprefix $(PROCESS_DIR), $(addsuffix .o, $(FILES_PROCESS)))

OBJS = $(OBJS_CMD) $(OBJ_MAIN) $(OBJS_UTILS) $(OBJS_START) $(OBJS_PROCESS) $(OBJS_ERRORMNG)
SRCS = $(SRCS_CMD) $(FILE_MAIN) $(SRCS_UTILS) $(SRCS_UTILS) $(SRCS_PROCESS) $(SRCS_ERRORMNG)

all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS_FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
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

do_clean:	all clean

.PHONY: all clean fclean re libft do_clean
.SILENT: