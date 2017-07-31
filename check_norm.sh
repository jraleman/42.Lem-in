# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_norm.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/31 06:16:50 by jaleman           #+#    #+#              #
#    Updated: 2017/07/31 06:16:51 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

norminette srcs/ && \
norminette includes/ && \
norminette libft/srcs/ && \
norminette libft/includes/
