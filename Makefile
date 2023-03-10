# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 23:55:26 by alboudje          #+#    #+#              #
#    Updated: 2022/12/30 15:54:28 by alboudje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	so_long
CC 				= 	gcc

LIBFT 			= 	libft/libft.a
LIBFT_FILES		= 	libft/*.c libft/*.h libft/Makefile

SRC_FOLDER		= 	Mandatory/
SRC_FILES		= 	main.c \
					so_long.c \
					player.c \
					player_physics.c \
					player_utils.c \
					game.c \
					level.c \
					level_utils.c \
					inputs.c \
					map.c \
					map_utils.c \
					map_utils2.c \
					hud.c \
					enemy.c \
					enemy_utils.c \
					ILX_Rect.c \
					ILX_Texture.c \
					ILX_Rects.c \
					ILX_Rect_utils.c \
					ILX_Window.c
					
SRC 			= 	$(addprefix $(SRC_FOLDER), $(SRC_FILES))

INCLUDES_FILES 	= 	ILX.h \
					ILX_Keycodes.h \
					ILX_Rect.h \
					ILX_Texture.h \
					ILX_Window.h \
					map.h \
					player.h \
					so_long.h

INCLUDES 		= 	$(addprefix $(SRC_FOLDER), $(INCLUDES_FILES))

OBJ 			= 	${SRC:.c=.o}
CFLAGS 			= 	-Wall -Wextra -Werror# -g3 -fsanitize=address
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FOLDER		=	mlx_linux
	MLX_FLAGS		= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_CCFLAGS		= 	-I/usr/include -Imlx_linux -O3
else
	MLX_FOLDER		= 	mlx
	MLX_FLAGS		= 	-Lmlx -lmlx -framework OpenGL -framework AppKit
	MLX_CCFLAGS		= 	-Imlx
endif

all : title $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@printf ">$(MLX_FOLDER)"
	@make -C $(MLX_FOLDER)/
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -lm $(MLX_FOLDER)/libmlx.a $(LIBFT)
	@printf "$(GREEN)Creating $(CYAN)$(NAME)$(END): OK\n"

%.o : %.c $(INCLUDES) Makefile $(LIBFT_FILES)
	@$(CC) $(CFLAGS) $(MLX_CCFLAGS) -o $@ -c $<
	@printf "$(GREEN)Compiling $(NAME): $(CYAN)$<: $(GREEN)OK$(END)\n"

clean :
	-rm -f $(OBJ)
	-make clean -C libft
	-make clean -C $(MLX_FOLDER)

fclean : clean
	-rm -f $(NAME)
	-make fclean -C libft
	-make fclean -C $(MLX_FOLDER)

re : fclean all

title :
	@printf "  _________          .____                         		\n"
	@printf	" /   _____/ ____     |    |    ____   ____   ____ 			\n" 
	@printf " \\_____  \\ /  _ \\    |    |   /  _ \\ /    \\ / ___\\ 	\n"
	@printf " /        (  <_> )   |    |__(  <_> |   |  / /_/  >		\n"
	@printf "/_______  /\\_________|_______ \\____/|___|  \\___  /		\n" 
	@printf "        \\/     /_____/       \\/          \\/_____/ 		\n"
	@printf "_________________________________________$(RED)alboudje$(END)_\n"

.PHONY: all clean fclean re

END		=\x1b[0m
BOLD	=\x1b[1m
UNDER	=\x1b[4m
REV		=\x1b[7m

# Colors
GREY	=\x1b[30m
RED		=\x1b[31m
GREEN	=\x1b[32m
YELLOW	=\x1b[33m
BLUE	=\x1b[34m
PURPLE	=\x1b[35m
CYAN	=\x1b[36m
WHITE	=\x1b[37m

# Colored backgrounds
IGREY	=\x1b[40m
IRED	=\x1b[41m
IGREEN	=\x1b[42m
IYELLOW	=\x1b[43m
IBLUE	=\x1b[44m
IPURPLE	=\x1b[45m
ICYAN	=\x1b[46m
IWHITE	=\x1b[47m
