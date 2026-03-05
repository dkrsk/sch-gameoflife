TARGET=Game_of_life
SRCS=	gol_core.c \
		gol_io.c \
		game_of_life.c

FLAGS = -Werror -Wextra -Wall -std=c11

all:
	gcc $(FLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f $(SRCS_DIR)/**/*.o $(SRCS_DIR)/**/*.gch $(SRCS_DIR)/**/*.a $(SRCS_DIR)/**/*.so

rebuild: clean all