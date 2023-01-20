# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 15:15:32 by artadevo          #+#    #+#              #
#    Updated: 2022/12/24 18:50:47 by artadevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

ALL_SRCS = $(wildcard */*.c)

OBJS = $(patsubst %.c, %.o, $(ALL_SRCS))

INCLUDES = -I ./libs

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -lreadline -o $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re



# , all, clean, fclean, re

# CC	=	cc

# CFLAGS = -I./libs -Wall -Wextra -Werror

# ALL_SRCS = $(wildcard ./sources/*.c)

# OBJS = $(patsubst %.c, %.o, $(ALL_SRCS))

# RM = rm -f

# INCLUDES = -I ./libs -Imlx

# LIB_BIN = mlx/libmlx.a

# FRAMEWORKS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# all: $(NAME) 

# $(NAME): $(OBJS) $(LIB_BIN)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(FRAMEWORKS)
# $(LIB_BIN):
# 	$(MAKE) -C mlx;

# clean:
# 	$(RM) $(OBJS) $(OBJS_BONUS)
# 	$(MAKE) -C mlx clean

# fclean: clean
# 	$(RM) $(NAME) $(NAME_BONUS)

# re:	fclean all

# .PHONY: all clean fclean re bonus


