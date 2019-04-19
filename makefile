CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)

.PHONY: clean

all:bin build bin/main.exe 

bin/main.exe:  build/main.o build/board_print_plain.o build/board.o build/board_read.o
	g++ $^ -o $@ $(CFLAGS)

build/board_print_plain.o: src/board_print_plain.cpp src/board_print_plain.h
	$(OBJ)

build/board_read.o: src/board_read.cpp src/board_read.h
	$(OBJ)

build/board.o: src/board.cpp src/board.h
	$(OBJ)

build/main.o: src/main.cpp
	$(OBJ)

bin: 
	mkdir bin
build:
	mkdir build

clean:
	rm build/*.o
	rm bin/*.exe
    

