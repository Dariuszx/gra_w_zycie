CC =
CFLAGS = -ansi -pedantic
HEADERS = ../modules/headers
LIBS = ../modules/lib
OBJECTS = main.o arg_handling.o error_handling.o data_loading.o cellular_automaton.o data_saving.o image_generation.o cellular_select_rules.o cellular_formation_generation.o mesh.o graphics.o 

OBJECTS += garbage_collection.o

main.o arg_handling.o cellular_automaton.o : $(HEADERS)/args.h
garbage_collection.o data_loading.o cellular_automaton.o data_saving.o image_generation.o mesh.o: $(HEADERS)/mesh.h
cellular_automaton.o garbage_collection.o : $(HEADERS)/rules.h
main.o : $(HEADERS)/bool.h
arg_handling.o cellular_automaton.o mesh.o data_loading.o data_saving.o error_handling.o image_generation.o: $(HEADERS)/error_handling.h
main.o cellular_automaton.o image_generation.o graphics.o arg_handling.o data_saving.o : $(HEADERS)/graphics.h
main.o cellular_formation_generation.o cellular_automaton.o : $(HEADERS)/garbage_collection.h

debug : CFLAGS += -Wall -DDEBUG -g
debug : CC += @cc

debug: $(OBJECTS)
	@echo "Łącze moduły *.o"
	$(CC) -o $@ -g $^

gra_w_zycie : CC += @cc
gra_w_zycie: $(OBJECTS)
	@echo "Łącze moduły *.o"
	@$(CC) -o $@ $^

main.o: ../main.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^
mesh.o: $(LIBS)/mesh.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

arg_handling.o: $(LIBS)/arg_handling.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

error_handling.o: $(LIBS)/error_handling.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

data_loading.o: $(LIBS)/data_loading.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

cellular_automaton.o: $(LIBS)/cellular_select_rules.c $(LIBS)/cellular_formation_generation.c $(LIBS)/cellular_automaton.c \
						$(HEADERS)/data_saving.h $(HEADERS)/image_generation.h $(HEADERS)/cellular_automaton.h
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

data_saving.o: $(LIBS)/data_saving.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

image_generation.o: $(LIBS)/image_generation.c	
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

graphics.o: $(LIBS)/graphics.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

garbage_collection.o: $(LIBS)/garbage_collection.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

.PHONY: clean

clean:
	rm *.o
	rm ../modules/headers/*.gch
