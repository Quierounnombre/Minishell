NAME = minishell
LIBFT = libft_def/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(RL_INC)#-g3 -fsanitize=address
LIBS_FLAGS = -lreadline

RL_LIB = -L /Users/$(USER)/.brew/opt/readline/lib
RL_INC = -I /Users/$(USER)/.brew/opt/readline/include

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

FILES_CMD = cmd_executer \
			is_built_in \
			do_built_in \
			echo \
			pwd \
			env \
			cd \
			export \
			exit \
			unset \
			more_built_in \
			sort_export \

CMD_DIR = ./srcs/cmd/
SRCS_CMD = $(addprefix $(CMD_DIR), $(addsuffix .c, $(FILES_CMD)))
OBJS_CMD = $(addprefix $(CMD_DIR), $(addsuffix .o, $(FILES_CMD)))

FILES_UTILS = ft_cleanchild \
			ft_storechild \
			ft_cleancmd \
			ft_storecmd \
			ft_delete_file \
			find_string \
			space_tab \
			find_start_of_str \
			lstadd_back_nodo \
			ft_path \

UTILS_DIR = ./srcs/utils/
SRCS_UTILS = $(addprefix $(UTILS_DIR), $(addsuffix .c, $(FILES_UTILS)))
OBJS_UTILS = $(addprefix $(UTILS_DIR), $(addsuffix .o, $(FILES_UTILS)))

FILES_ERRORMNG = ft_cleanshell \
				ft_error \

ERRORMNG_DIR = ./srcs/errormng/
SRCS_ERRORMNG = $(addprefix $(ERRORMNG_DIR), $(addsuffix .c, $(FILES_ERRORMNG)))
OBJS_ERRORMNG = $(addprefix $(ERRORMNG_DIR), $(addsuffix .o, $(FILES_ERRORMNG)))

FILES_START = init_shell_struct \
			clone_env \
			start \
			init_signals \

START_DIR = ./srcs/startup/
SRCS_START = $(addprefix $(START_DIR), $(addsuffix .c, $(FILES_START)))
OBJS_START = $(addprefix $(START_DIR), $(addsuffix .o, $(FILES_START)))

FILES_PROCESS = input_redirect \
				mng_redirections \
				output_redirection \
				output_append \
				make_childs \
				ft_child \
				process_executer \
				fork_child \
				reset_shell \
				fix_the_stdred_struct \

PROCESS_DIR = ./srcs/Process/
SRCS_PROCESS = $(addprefix $(PROCESS_DIR), $(addsuffix .c, $(FILES_PROCESS)))
OBJS_PROCESS = $(addprefix $(PROCESS_DIR), $(addsuffix .o, $(FILES_PROCESS)))

FILES_PARSE = check_pipes \
			  check_pipes2 \
			  count_env \
			  count  \
			  env \
			  fill_node \
			  fill_node2 \
			  fill_node3 \
			  fill_node4 \
			  new_nodo \
			  parse \
			  quotation_marks \
			  redirection \
			  separation_nodo \
			  separation \
			  variable_qm \
			  variable_qm2 \
			  error \
			  heredoc \
			  check_redirection \

PARSE_DIR = ./srcs/parse/
SRCS_PARSE = $(addprefix $(PARSE_DIR), $(addsuffix .c, $(FILES_PARSE)))
OBJS_PARSE = $(addprefix $(PARSE_DIR), $(addsuffix .o, $(FILES_PARSE)))

FILES_SIGNAL =	sig_handler \
				sig_d \

SIGNAL_DIR = ./srcs/signal/
SRCS_SIGNAl = $(addprefix $(SIGNAL_DIR), $(addsuffix .c, $(FILES_SIGNAL)))
OBJS_SIGNAL = $(addprefix $(SIGNAL_DIR), $(addsuffix .o, $(FILES_SIGNAL)))

OBJS = $(OBJS_CMD) $(OBJ_MAIN) $(OBJS_UTILS) $(OBJS_START) $(OBJS_PROCESS) $(OBJS_ERRORMNG) $(OBJS_PARSE) $(OBJS_SIGNAL)
SRCS = $(SRCS_CMD) $(FILE_MAIN) $(SRCS_UTILS) $(SRCS_UTILS) $(SRCS_PROCESS) $(SRCS_ERRORMNG) $(SRCS_PARSE) $(SRCS_SIGNAl)

all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(RL_LIB)
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