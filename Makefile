# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 15:15:32 by artadevo          #+#    #+#              #
#    Updated: 2023/01/22 22:42:41 by artadevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

CC				=	cc

LIBFT_DIR		=	libft

LIBFT			=	$(LIBFT_DIR)/libft.a

PREFIX			=	$(shell find ${HOME} -type d -name readline_out)

INC				=	-Iinc -I$(LIBFT_DIR)

READLINE_DIR	=	readline

READLINE_OUT	=	"${HOME}/readline_out/"

READLINE_INC	=	-I$(READLINE_OUT)/include

READLINE_LIB	=	$(READLINE_OUT)lib

INCLUDES		=	$(INC) $(READLINE)

LINKERS			=	-L$(READLINE_LIB) -lreadline -L$(LIBFT_DIR) -lft

CFLAGS			=	#-Wall -Wextra -Werror # m-fsanitize=address -g

OBJS_DIR		=	objs

SRCS			=	$(wildcard src/*.c)

OBJS			=	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

MKDIR			=	mkdir -p

RM				=	rm -rf

.DEFAULT_GOAL	=	all

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)
$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

$(READLINE_OUT):
	mkdir -p $(READLINE_OUT)

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

readline: $(READLINE_OUT)
	@cd readline && ./configure --prefix=$(PREFIX) && make clean && make && make install

.PHONY: all clean fclean re readline

# NAME =  minishell

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# SRCS = $(wildcard */*.c)

# LIB_SRCS = $(wildcard ./libft/*.c)

# ALL_SRCS = $(filter-out $(SRCS) - $(LIB_SRCS))

# OBJS = $(patsubst %.c, %.o, $(ALL_SRCS))

# INCLUDES = -I ./include

# RM = rm -f

# %.o: %.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# all: $(NAME) 

# $(NAME): $(OBJS) 
# 	$(CC) $(CFLAGS) $(INCLUDES) -lreadline -o $(NAME) $(OBJS) 

# clean:
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(RM) $(NAME)

# re:	fclean all

# .PHONY: all clean fclean re



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