NAME = so_long

SRCS	=	./main.c get_next_line_utils.c get_next_line.c\
./check_map_path.c ./check_map.c ./utils_message.c ./load_map.c ./parse_map.c\
./putnbr_and_images.c ./draw_lines.c ./moves.c\

OBJS	=	${SRCS:%.c=${OBJ_D}%.o}

SRC_D =	src/

OBJ_D = objs/

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = so_long.h

all		:
	@make --no-print-directory -C ./mlx
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.c headers/so_long.h
	${CC} ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile headers/so_long.h mlx/mlx.h
	${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -o ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	make clean -C ./mlx
	rm -rf ${OBJ_D}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re