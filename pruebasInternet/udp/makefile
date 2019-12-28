headers = /
compilador=gcc
CFLAGS=-I$(headers)

include = udpServer.h udpClient.h
objects = udpServer.o udpClient.o

OBJ = $(objects)

$%.o: %.c $(dependencias)
	$(compilador) -c -o $@ $< $(CFLAGS)

servidor: $(OBJ)
	$(compilador) -o $@ $^ $(CFLAGS) main.c

.PHONY: clean

clean:
	rm -f $/*.o
	rm -f servidor
