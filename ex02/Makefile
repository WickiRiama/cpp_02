# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 16:22:44 by mriant            #+#    #+#              #
#    Updated: 2022/11/08 16:20:51 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS = ${addprefix srcs/, \
	Fixed.cpp \
	main.cpp}

OBJS = ${SRCS:srcs/%.cpp=build/%.o}
DEPS = ${SRCS:srcs/%.cpp=build/%.d}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
IFLAGS = -MMD -I./includes
LFLAGS =

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

build/%.o: srcs/%.cpp
	mkdir -p build
	${CXX} ${CXXFLAGS} -c $< -o $@ ${IFLAGS}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}