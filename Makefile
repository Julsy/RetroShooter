# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 13:21:35 by iiliuk            #+#    #+#              #
#    Updated: 2017/07/09 22:11:24 by iiliuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_retro

SRCS =	main.cpp \
		Player.class.cpp \
		Game.class.cpp \
		Enemy.class.cpp \
		Bullet.class.cpp \
		GameObject.class.cpp \
		GameEntity.class.cpp \
		EnemyBullet.class.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -lncurses $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all
