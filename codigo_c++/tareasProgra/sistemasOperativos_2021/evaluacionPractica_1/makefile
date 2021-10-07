CC=g++
CFLAGS=-lpthread

MY_SOURCES = sincronizacion_semaforos.cpp
MY_OBJS = $(patsubst %.cpp,%.o, $(MY_SOURCES))

all: semaforos

%o: %.cpp
	$(CC) $(CFLAGS) $<

semaforos: $(MY_OBJS)
	$(CC) $(CFLAGS) $^ -o $@
