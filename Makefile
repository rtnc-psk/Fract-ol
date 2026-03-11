NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = src/main.c src/mandelbrot.c src/utils.c
OBJS        = $(SRCS:.c=.o)

MLX_DIR     = ./include/MLX42
MLX_LIB     = $(MLX_DIR)/build/libmlx42.a
INCLUDES    = -I ./include -I $(MLX_DIR)/include/MLX42
MLX_FLAGS   = -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
