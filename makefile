all: remov_dupli
remov_dupli: main.o array.o linked_list.o
	g++ main.o array.o linked_list.o -o sort.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

linked_list.o: linked_list.cpp
	g++ -c linked_list.cpp -o linked_list.o

array.o: array.cpp
	g++ -c array.cpp -o array.o

clean:
	rm *.o
