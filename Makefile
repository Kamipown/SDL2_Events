NAME =	SDL2_Events

FLG =	-Wall -Wextra -Werror

SRC =	srcs/main.c \
		srcs/initialization.c \
		srcs/window.c \
		srcs/events.c

INC =	-I./include

all: $(NAME)

$(NAME):
	gcc $(FLG) $(SRC) $(INC) -lSDL2 -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
