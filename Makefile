CC=gcc
TARGET=main
 
all:    main.o board.o utils.o
	$(CC) main.c board.c utils.c -lm -o $(TARGET)

clean:
	rm *.o $(TARGET)