all: project clean run
	
project: main.o sparse_matrix.o
	g++ main.o sparse_matrix.o -o project

main.o: main.cpp
	g++ -c main.cpp

sparse_matrix.o: sparse_matrix.cpp
	g++ -c sparse_matrix.cpp
clean:
	rm -rf *.o
run:
	./project
