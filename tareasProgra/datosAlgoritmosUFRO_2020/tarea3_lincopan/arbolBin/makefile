all:
	cp ../arbol/bin/*.o ./bin/
	g++ -g -o ./bin/arbolBin.o arbolBin.cpp -c
	g++ -g -o ./bin/main.o main.cpp -c
	g++ -g ./bin/*.o -o main
clean:
	rm ./bin/*.o main
run:
	./main
