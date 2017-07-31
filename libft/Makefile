# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 23:46:05 by jaleman           #+#    #+#              #
#    Updated: 2016/11/03 23:46:08 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libft.a

INC_DIR := includes
SRC_DIR := srcs
OBJ_DIR := objs

INCLS   := $(INC_DIR)
SRCS    := ft_atoi.c ft_isdigit.c ft_isspace.c ft_lst_rec_free.c \
           ft_lstforeach.c ft_lstpush.c ft_memdel.c ft_putchar_fd.c \
					 ft_putstr_fd.c ft_puterror_fd.c ft_strchr.c ft_strcmp.c \
					 ft_strdel.c ft_strdup.c ft_strequ.c ft_strlchr.c ft_strlen.c \
					 ft_strsub.c get_next_line.c ft_strjoin.c ft_strcpy.c ft_strcat.c \
					 ft_strnew.c ft_putendl_fd.c ft_mini_printf.c ft_itoa.c \
					 ft_putnbr_fd.c ft_lstdelnode.c ft_lstdelone.c ft_lstadd.c \
					 ft_lstfind.c ft_lstnew.c ft_memcpy.c

OBJS    := $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC      := gcc
CFLAGS  += -Wall -Wextra -Werror
LFLAGS  += -I.
AR      := ar rc
RLIB    := ranlib

all:	obj $(NAME)

obj:
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@echo "[INFO] $(NAME) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INCLS)

clean:
		@rm -rf $(OBJS) $(OBJ_DIR)
		@echo "[INFO] Objects removed!"

fclean: clean
		@rm -rf $(NAME) $(LIB_DIR)
		@echo "[INFO] Library [$(NAME)] removed!"

re:		fclean all

.PHONY:	all clean fclean re
