headers = include
compilador=gcc
CFLAGS=-I$(headers)

objectsDIR=obj

include = udpServer.h udpClient.h
objects = udpServer.o udpClient.o

OBJ = $(patsubst %,$(objectsDIR)/%,$(objects))

$(objectsDIR)/%.o: src/%.c
	$(compilador) -c -o $@ $< $(CFLAGS)

servidor: $(OBJ)
	$(compilador) -o $@ $^ $(CFLAGS) src/main.c

clean:
	rm -f $(objectsDIR)/*.o
	rm -f servidor
