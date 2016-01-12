NAME = SDL2_Events

FLG = -Wall -Wextra -Werror

SRC =	srcs/main.c \
		srcs/initialization.c \
		srcs/window.c \
		srcs/events.c

all: $(NAME)

$(NAME):
	gcc $(FLG) $(SRC) -o $(NAME) -lSDL2

clean:
	rm -f $(NAME)

re: clean all
