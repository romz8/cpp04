# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:01:21 by rjobert           #+#    #+#              #
#    Updated: 2024/01/26 14:30:14 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = Abstract
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -I ./
SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp Brain.cpp
HEADER = Animal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)
RM = rm -rf

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)


%.o: %.cpp Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all


