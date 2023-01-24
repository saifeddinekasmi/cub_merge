CC = cc
RM = rm -rf
XFLAGS = -Wall -Wextra -Werror  -Imlx -fsanitize=address -g

SRC =  	main.c cub3d_outils.c draw_minimap.c init.c move_player.c dda.c check_walls.c \
		parsing/cub3d.c \
		parsing/parssing/pars_rgb/pars_rgb.c \
		parsing/parssing/pars_rgb/pars_rgb_2.c \
		parsing/parssing/pars_rgb/utils_rgb.c \
		parsing/parssing/pars_map/pars_map.c \
		parsing/parssing/pars_map/pars_map_2.c \
		parsing/parssing/pars_map/pars_map_3.c \
		parsing/get_next_line/get_next_line.c \
		parsing/get_next_line/get_next_utils.c \
		parsing/libft/ft_strlen.c \
		parsing/libft/ft_split.c \
		parsing/libft/ft_strtrim.c \
		parsing/libft/ft_memmove.c \
		parsing/libft/ft_substr.c \
		parsing/libft/ft_strdup.c \
		parsing/libft/ft_strncmp.c \
		parsing/libft/ft_strnstr.c \
		parsing/libft/ft_memcpy.c \
		parsing/libft/ft_memset.c \
		parsing/libft/ft_strcpy.c \
		parsing/libft/ft_isdigit.c \
		parsing/libft/ft_putstr_fd.c \
		parsing/libft/ft_atoi.c \
		ray_tools.c

OBJ = ${SRC:.c=.o}
NAME = cub
LIB  = header.h parsing/cub3d.h

all : ${NAME}

${NAME} : ${OBJ} ${LIB}
		${CC} -g ${XFLAGS} ${OBJ}  -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		
%.o : %.c ${LIB}
	${CC} -g ${XFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM}  ${NAME}

re: fclean all

.PHONY: clean fclean re all