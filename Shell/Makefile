# ************************************************************************** #
#                                                                            #
#                                                                            #
#   Makefile                                                                 #
#                                                                            #
#   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             #
#                                                             / \__          #
#                                                            (    @\___      #
#                                                             /         O    #
#   Created: 2024/05/16 21:17:51 by Tiago                    /   (_____/     #
#   Updated: 2024/06/14 07:00:24 by Tiago                 /_____/ U          #
#                                                                            #
# ************************************************************************** #

NAME		=	shell
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -rf
MKDIR		=	mkdir -p
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-I/usr/local/opt/readline/include
# CFLAGS		+=	-fsanitize=address -g3
READLINE	=	-lreadline
READLINE	+=	-L/usr/local/opt/readline/lib
SRCS_FILES	=	ms_expand_dollar_utils \
				ms_heredoc_tree_queue \
				ms_executor_struct \
				ms_check_dangling \
				ms_executor_utils \
				ms_expand_dollar \
				ms_expand_second \
				ms_expander_util \
				ms_executor_tree \
				ms_expand_first \
				ms_export_utils \
				ms_expand_files \
				ms_expand_star \
				ms_lexer_utils \
				ms_executor_io \
				ms_get_abspath \
				ms_list_utils \
				ms_pipe_list \
				ms_executor \
				ms_expander \
				ms_cmd_list \
				ms_io_list \
				ms_heredoc \
				ms_helper \
				ms_signal \
				ms_export \
				ms_parser \
				ms_error \
				ms_unset \
				ms_lexer \
				ms_token \
				ms_main \
				ms_echo \
				ms_exit \
				ms_env \
				ms_pwd \
				ms_cd
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

all:			
				$(MKDIR) $(OBJS_DIR)
				make libft $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ $(READLINE) -Llibft -lft -o $@
				
libft:
				make -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				$(RM) $(NAME)

re:				fclean all

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./shell

.PHONY:			all libft clean fclean re