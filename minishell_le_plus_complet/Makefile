CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell
RM = rm -f

SRCS = minishell.c \
	adv_tokeniser1.c \
	adv_tokeniser2.c \
	parser1.c \
	parser2.c \
	pipeline.c \
	signal.c \
	handle_dollar.c \
	handle_paths.c \
	heredoc.c \
	get_env_paths.c \
	env_management.c \
	free_terminal.c \
	string_utils.c \
	write_content.c \
	manage_env_list.c \
	parse_command_line.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft/

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
