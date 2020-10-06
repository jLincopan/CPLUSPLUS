all:
	cp ../arbol/bin/*.o ./bin/
	g++ -g -o ./bin/arbolBin.o arbolBin.cpp -c
	g++ -g -o ./bin/main.o main.cpp -c
	g++ -g ./bin/*.o -o main
	./main

debug:
	cp ../arbol/bin/*.o ./bin/
	g++ -g -fsanitize=address -o ./bin/arbolBin.o arbolBin.cpp -c
	g++ -g -fsanitize=address -o ./bin/main.o main.cpp -c
	g++ -fsanitize=address -g ./bin/*.o -o main
	./main
clean:
	rm ./bin/*.o main
run:
	./main
