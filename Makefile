# ************************************************************************** #
#                                                                            #
#                                                                            #
#   Makefile                                                                 #
#                                                                            #
#   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             #
#                                                             / \__          #
#                                                            (    @\___      #
#                                                             /         O    #
#   Created: 2024/05/16 20:42:26 by Tiago                    /   (_____/     #
#   Updated: 2024/05/16 20:57:54 by Tiago                  /_____/ U         #
#                                                                            #
# ************************************************************************** #

NAME		=	shell
LIBFT		=	libft.a
ARRC		=	ar rcs
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-I/usr/local/opt/readline/include
CPPFLAGS	=	-L/usr/local/opt/readline/lib -lreadline
# CFLAGS		+=	-lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include
# CFLAGS		+=	-fsanitize=address -g3
SRCS_FILES	=	ms_main_bonus
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

# export	LDFLAGS="-L/usr/local/opt/readline/lib"
# export	CPPFLAGS="-I/usr/local/opt/readline/include"
# export	PKG_CONFIG_PATH="/usr/local/opt/readline/lib/pkgconfig"

all:			
				mkdir -p $(OBJS_DIR)
				make create_libft
				make $(NAME)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CPPFLAGS) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(SRCS) -o $(NAME)

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