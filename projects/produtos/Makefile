TARGET := projeto

all: $(TARGET)

$(TARGET) : projeto.o main.o
	gcc -g -o $(TARGET) projeto.o main.o

main.o: main.c
	gcc -g -c main.c -o main.o

projeto.o: projeto.c 
	gcc -g -c projeto.c -o projeto.o

clean:
	rm -rf *.o $(TARGET)

run:
	./$(TARGET)