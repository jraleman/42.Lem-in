#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 20:06:37 by jaleman           #+#    #+#              #
#    Updated: 2017/07/29 20:06:38 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make && \
cp lem-in resources/tests && \
cd resources/tests && \
if [ "$1" == "debug" ]; then \
	sh autolemin_debug.sh; \
else \
	sh autolemin.sh; \
fi && \
rm -f lem-in
