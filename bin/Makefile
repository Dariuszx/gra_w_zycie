CC = cc
CFLAGS = -Wall -ansi -pedantic
HEADERS = ../modules/headers
LIBS = ../modules/lib
OBJECTS = main.o arg_handling.o error_handling.o data_loading.o cellular_automaton.o data_saving.o image_generation.o 

gra_w_zycie: $(OBJECTS)
	$(CC) -o $@ $^

main.o: ../main.c $(HEADERS)/args.h
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"

arg_handling.o: $(LIBS)/arg_handling.c $(HEADERS)/args.h
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

error_handling.o: $(LIBS)/error_handling.c
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"

data_loading.o: $(LIBS)/data_loading.c $(HEADERS)/mesh.h
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"

cellular_automaton.o: $(LIBS)/cellular_automaton.c $(HEADERS)/args.h $(HEADERS)/mesh.h $(HEADERS)/rules.h $(HEADERS)/data_saving.h $(HEADERS)/image_generation.h
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"

data_saving.o: $(LIBS)/data_saving.c $(HEADERS)/mesh.h
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"	

image_generation.o: $(LIBS)/image_generation.c $(HEADERS)/mesh.h	
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
	@echo "Kompiluję moduł $@"




