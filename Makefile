# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:56:04 by jaleman           #+#    #+#              #
#    Updated: 2017/02/21 15:56:05 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME       = lem-in

# Compiling flags
#FLAGS      = -Wall -Wextra -Werror -g -Ofast
FLAGS      = -g -Ofast

# Folders
SRC_DIR    = ./srcs/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/
LIBFT_DIR  = ./libft/

# Source files and object files
SRC_FILES  =  main.c lemin_read.c lemin_validate.c lemin_end.c lemin_print.c \
              lemin_init.c get_ants_total.c init_ants.c init_path.c init_room.c\
              get_room_flag.c get_room_name.c lemin_start.c lemin_loop.c \
              lemin_play.c find_room.c get_params.c lemin_debug.c

OBJ_FILES  = $(SRC_FILES:.c=.o)

# Paths
SRC        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT      = $(addprefix $(LIBFT_DIR), libft.a)

# Libft and Minilibx linkers
LNK        = -L $(LIBFT_DIR) -lft -Ofast

# all rule
all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(LIBFT_DIR)/includes -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) removed!"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
