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
#   Updated: 2024/05/16 21:25:39 by Tiago                  /_____/ U         #
#                                                                            #
# ************************************************************************** #

NAME		=	shell
LIBFT		=	libft.a
ARRC		=	ar rcs
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		+=	-I/usr/local/opt/readline/include
# CFLAGS		+=	-fsanitize=address -g3
READLINE	=	-lreadline
# READLINE	=	-L/usr/local/opt/readline/lib -lreadline
SRCS_FILES	=	ms_error_bonus \
				ms_main_bonus \
				ms_cd_bonus
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

all:			
				mkdir -p $(OBJS_DIR)
				make create_libft
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(READLINE) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(SRCS) -o $(NAME)

create_libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all create_libft clean fclean re