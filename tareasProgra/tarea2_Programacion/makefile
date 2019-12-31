headers = include
compilador=g++
CFLAGS=-I$(headers)

objectsDIR=obj

include = conecta4.h toqueFama.h
objects = conecta4.o toqueFama.o

OBJ = $(patsubst %,$(objectsDIR)/%,$(objects))

$(objectsDIR)/%.o: src/%.cpp
	$(compilador) -c -o $@ $< $(CFLAGS)

juegos: $(OBJ)
	$(compilador) -o $@ $^ $(CFLAGS) src/main.cpp

clean:
	rm -f $(objectsDIR)/*.o
	rm -f juegos
