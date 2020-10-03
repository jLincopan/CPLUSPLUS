all:
#	cp ../pila/bin/*.o ./bin/
	g++ -o ./bin/lista.o ./lista/lista.cpp -c
	g++ -o ./bin/arbol.o arbol.cpp -c
	g++ -o ./bin/main.o main.cpp -c
	g++ ./bin/*.o -o main
clean:
	rm ./bin/*.o main
run:
	./main
