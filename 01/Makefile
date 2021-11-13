all: compile run

compile:
	g++ -fdiagnostics-color=always -g -I./include/utility -I./include ./src/utility/*.cpp ./src/*.cpp -o ./build/main.exe
run: 
	./build/main.exe