main: main.o classesFunc.o subRotine_1.o subRotine_2.o InputMatrix.o
	g++ main.o classesFunc.o subRotine_1.o subRotine_2.o InputMatrix.o -o MatrizFutura

main.o: main.cpp ./HEADERS/mainHeader.h
	g++ -c main.cpp -o main.o

classesFunc.o: ./CLASSES/classesFunc.cpp ./HEADERS/mainHeader.h
	g++ -c ./CLASSES/classesFunc.cpp -o classesFunc.o

subRotine_1.o: ./MODULES/subRotine_1.cpp ./HEADERS/mainHeader.h
	g++ -c ./MODULES/subRotine_1.cpp -o subRotine_1.o

subRotine_2.o: ./MODULES/subRotine_2.cpp ./HEADERS/mainHeader.h
	g++ -c ./MODULES/subRotine_2.cpp -o subRotine_2.o

InputMatrix.o: ./MODULES/InputMatrix.cpp ./HEADERS/mainHeader.h
	g++ -c ./MODULES/InputMatrix.cpp -o InputMatrix.o

exec:
	./MatrizFutura

limpar:
	rm main.o classesFunc.o subRotine_1.o subRotine_2.o InputMatrix.o