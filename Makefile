# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 03:11:53 by mokoucha          #+#    #+#              #
#    Updated: 2022/04/24 05:44:39 by mokoucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#export LD_LIBRARY_PATH=/usr/lib/swift/

# Binary

NAME = so_long
NAME_BONUS = ./bonus/so_long_bonus

# Path

SRC_PATH = ./srcs/
SRC_PATH_BONUS = ./bonus/srcs/

OBJ_PATH = ./objs/
OBJ_PATH_BONUS = ./bonus/objs/

WFLAGS = -I./includes/
WFLAGSBONUS = -I./bonus/includes/

HEADER = ./includes/so_long.h
HEADER_BONUS = ./bonus/includes/so_long.h

LIBFT_PATH	= ./libs/libft/libft.a

GNL_PATH = ./libs/gnl/gnl.a

# Name

SRC_NAME =	ini_png.c			\
			parsing.c			\
			error.c				\
			open_file.c			\
			utils.c				\
			trace_img_logic.c	\
			hook_manager.c		\
			patch_mlx.c			\
			check_map.c			\
			main.c

SRC_BONUS =	ini_png_bonus.c			\
			parsing_bonus.c			\
			error_bonus.c				\
			open_file_bonus.c			\
			utils_bonus.c				\
			trace_img_logic_bonus.c	\
			hook_manager_bonus.c		\
			patch_mlx_bonus.c			\
			check_map_bonus.c			\
			main_bonus.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_BONUS = $(SRC_BONUS:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

OBJ_BONUS = $(addprefix $(OBJ_PATH_BONUS), $(OBJ_NAME_BONUS))

MAIN = main.c

MAIN_BONUS = ./bonus/main.c

# Flags

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror 

FS = #-fsanitize=address -g3

MLX = -L./libs/mlx -lmlx -framework OpenGL -framework AppKit -lz 

# Rules 

all: gnl lib mlx $(NAME) 

$(NAME): $(OBJ) $(LIBFT_PATH) $(GNL_PATH) $(HEADER) ./Makefile
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	export LD_LIBRARY_PATH=/usr/lib/swift/
	@$(CC) $(FS) $(LIBFT_PATH) $(GNL_PATH) $(OBJ) -o $@ $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_PATH) $(GNL_PATH) ./Makefile
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(FS) $(LIBFT_PATH) $(GNL_PATH) $(OBJ_BONUS) -o $(NAME_BONUS) $(MLX)
	@cp ./libs/mlx/libmlx.dylib ./bonus/libmlx.dylib
	@echo "\033[32m$(NAME_BONUS) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(WFLAGS) -o $@ -c $<

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c
	@mkdir $(OBJ_PATH_BONUS) 2> /dev/null || true
	@$(CC) $(WFLAGSBONUS) -o $@ -c $<

lib:
	@make -C./libs/libft/

gnl:
	@make -C ./libs/gnl

mlx:
	@make -C./libs/mlx/
	@cp ./libs/mlx/libmlx.dylib ./libmlx.dylib

bonus: gnl lib mlx $(NAME_BONUS)

clean: cleanbonus
	@make clean -C ./libs/libft/
	@make clean -C./libs/gnl/
	@make clean -C./libs/mlx/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@-rm -f $(OBJ)
	@-rmdir $(OBJ_PATH) 
	@echo "\033[31mFiles .o deleted\n\033[0m"

cleanbonus:
	@-rm -f $(OBJ_BONUS)
	@-rmdir $(OBJ_PATH_BONUS) 

fclean: clean
	@make fclean -C ./libs/libft/
	@make fclean -C ./libs/gnl/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@-rm -f $(NAME) $(NAME_BONUS) ./libmlx.dylib ./bonus/libmlx.dylib .vsvcode
	@-rm -d -rf .vsvcode
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	@norminette ./srcs/
	@norminette ./bonus/srcs/*.c
	@norminette ./bonus/includes/*.h
	@norminette ./includes/*.h
	@norminette ./libs/gnl/*.c 
	@norminette ./libs/gnl/*.h 
	@norminette ./libs/libft/*.c
	@norminette ./libs/libft/*.h 

git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all, clean, fclean, re