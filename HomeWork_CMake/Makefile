INC=-I./include

all: Polynomial main
		g++ $(INC) build/Polynomial.o build/main.o -o build/Polynomial

main: main.cc
		g++ $(INC) main.cc -c -o build/main.o

Polynomial: include/Polynomial.h src/Polynomial.cc
		g++ $(INC) src/Polynomial.cc -c -o build/Polynomial.o

clean:
		rm -rf build/*