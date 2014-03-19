CC = cc
CFLAGS = -Wall -ansi -pedantic
HEADERS = ../modules/headers
LIBS = ../modules/lib
OBJECTS = main.o

gra_w_zycie: $(OBJECTS)
	$(CC) -o $@ $^

main.o: ../main.c $(HEADERS)/args.h
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"
