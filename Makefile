CC=gcc
TARGET=main
all:
	$(CC) main.c src/board.c src/utils.c src/path.c src/coords.c src/city.c -lm -o $(TARGET)

clean:
	rm *.o $(TARGET)