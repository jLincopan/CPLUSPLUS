headers =../include
compilador=g++
CFLAGS=-I$(headers)

objectsDIR=obj

include = conecta4.h toqueFama.h
dependencias = $(patsubst %,$(headers)/%,$(include))

objects = conecta4.o toqueFama.o
OBJ = $(patsubst %,$(objectsDIR)/%,$(objects))


$(objectsDIR)/%.o: %.cpp $(dependencias)
	$(compilador) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(compilador) -o $@ $^ $(CFLAGS) main.cpp

.PHONY: clean

clean:
	rm -f $(objectsDIR)/*.o *~ core $(INCDIR)/*~
