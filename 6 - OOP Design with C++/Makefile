all: output

output: main.o 
	g++  main.o  GTUSet.o GTUIterator.o GTUVector.o -o output

main.o: main.cpp
	g++ -c -std=c++11 main.cpp GTUSet.cpp GTUIterator.cpp GTUVector.cpp

clean:
	rm *.o output