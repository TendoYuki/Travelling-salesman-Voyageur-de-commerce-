CC=gcc
TARGET=main
 
all:
	$(CC) main.c board.c utils.c -lm -o $(TARGET)

clean:
	rm *.o $(TARGET)