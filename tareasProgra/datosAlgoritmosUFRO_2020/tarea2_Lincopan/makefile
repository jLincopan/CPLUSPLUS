OUT = tdaEjecutable
CC = g++
ODIR = obj
SDIR = src
INC = -I src/include

_OBJS = listaClientes.o listaVendedores.o main.o manejoPantalla.o manejoArchivos.o manejoDatos.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -Wall -g -fsanitize=address -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	$(CC) -Wall -g -fsanitize=address $^ -o $(OUT)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)