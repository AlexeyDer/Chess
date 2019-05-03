CFLAGS = -Wall -Werror 
OBJ = gcc -c $< -o $@ $(CFLAGS)
TOBJ = build/main_test.o build/board.o  build/PrintBoard.o 


.PHONY: clean all bin build bin/tests.exe

all:bin build bin/main.exe bin/tests.exe

bin/main.exe:  build/main.o build/board.o  build/PrintBoard.o
	gcc $^ -o $@ $(CFLAGS)

build/PrintBoard.o: src/PrintBoard.c src/PrintBoard.h
	$(OBJ)

build/board.o: src/board.c src/board.h
	$(OBJ)

build/main.o: src/main.c
	$(OBJ)

bin/tests.exe:  $(TOBJ)
	gcc $(CFLAG)  $(TOBJ)  -o bin/tests.exe

build/main_test.o: test/main.c thirdparty/ctest.h src/board.h src/PrintBoard.h 
	gcc $(CFLAG) -I thirdparty -I src -c test/main.c -o build/main_test.o

bin: 
	mkdir -p bin
build:
	mkdir -p build
     
clean:
	rm -rf build/*.o
	rm -rf bin/*.exe
    

