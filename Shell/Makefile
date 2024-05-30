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
#   Updated: 2024/05/30 15:08:02 by Tiago                 /_____/ U          #
#                                                                            #
# ************************************************************************** #

NAME		=	shell
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-I/usr/local/opt/readline/include
CFLAGS		+=	-fsanitize=address -g3
READLINE	=	-lreadline
READLINE	+=	-L/usr/local/opt/readline/lib
SRCS_FILES	=	ms_expanderhelper \
				ms_exporthelper \
				ms_parseinput \
				ms_expandstar \
				ms_executor \
				ms_expander \
				ms_helper \
				ms_signal \
				ms_export \
				ms_error \
				ms_unset \
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
				mkdir -p $(OBJS_DIR)
				make libft
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ $(READLINE) -Llibft -lft -o $@

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all libft clean fclean re
