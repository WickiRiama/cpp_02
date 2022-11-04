# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 16:22:44 by mriant            #+#    #+#              #
#    Updated: 2022/11/04 16:33:37 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS = ${addprefix srcs/, \
	Fixed.cpp \
	main.cpp}

OBJS = ${SRCS:srcs/%.cpp=build/%.o}
DEPS = ${SRCS:srcs/%.cpp=build/%.d}

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
IFLAGS = -MMD -I./includes
LFLAGS =

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

build/%.o: srcs/%.cpp
	mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
clean: clean

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}