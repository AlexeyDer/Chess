CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)
TOBJ = build/main_test.o build/board.o  build/PrintBoard.o


.PHONY: clean

all:bin build bin/main.exe 

# test: bin/compile_test

bin/main.exe:  build/main.o build/board.o  build/PrintBoard.o
	g++ $^ -o $@ $(CFLAGS)

build/PrintBoard.o: src/PrintBoard.c src/PrintBoard.h
	$(OBJ)

build/board.o: src/board.c src/board.h
	$(OBJ)

build/main.o: src/main.c
	$(OBJ)

# bin/compile_test: $(TOBJ)
#     $(OBJ)  $(CFLAG) $(TOBJ) bin/compile_test

bin: 
	mkdir bin
build:
	mkdir build

clean:
	rm build/*.o
	rm bin/*.exe
    

