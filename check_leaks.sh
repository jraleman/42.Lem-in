#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_leaks.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/31 06:44:23 by jaleman           #+#    #+#              #
#    Updated: 2017/07/31 06:44:24 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# With valgrind
valgrind --tool=memcheck --leak-check=yes --track-origins=yes \
         --leak-check=full ./lem-in < resources/tests/maps/pdf_map1

# With leaks
./lem-in < resources/tests/maps/europe & leaks lem-in ; \
killall -9 lem-in
