CC=gcc
TARGET=main
 
all:
	$(CC) main.c board.c utils.c path.c coords.c city.c -lm -o $(TARGET)

clean:
	rm *.o $(TARGET)