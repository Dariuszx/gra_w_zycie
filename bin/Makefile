CC =
CFLAGS = -ansi -pedantic
HEADERS = ../modules/headers
LIB_DIR = ../modules/lib
GTK_SRC = ../modules/gtk/src
GTK_HEADERS = ../modules/gtk/headers
HEADER_PATH = -I$(HEADERS) -I$(GTK_HEADERS)
GTK = `pkg-config --cflags --libs gtk+-2.0`
OBJECTS = main.o arg_handling.o error_handling.o data_loading.o cellular_automaton.o data_saving.o image_generation.o cellular_select_rules.o cellular_formation_generation.o mesh.o graphics.o
OBJECTS += graphic_interface.o gtk.o gtk_actions.o gtk_menu.o

main.o arg_handling.o cellular_automaton.o gtk_ui.o: $(HEADERS)/args.h
data_loading.o cellular_automaton.o data_saving.o image_generation.o mesh.o gtk_ui.o : $(HEADERS)/mesh.h
cellular_automaton.o : $(HEADERS)/rules.h
main.o arg_handling.o : $(HEADERS)/bool.h
arg_handling.o cellular_automaton.o mesh.o data_loading.o data_saving.o error_handling.o image_generation.o gtk_ui.o : $(HEADERS)/error_handling.h
main.o cellular_automaton.o image_generation.o graphics.o arg_handling.o data_saving.o gtk_ui.o : $(HEADERS)/graphics.h
gtk.o gtk_ui.o gtk_actions.o gtk_menu.o: $(GTK_HEADERS)/gtk.h
main.o: $(GTK_HEADERS)/graphic_interface.h
gtk_menu.o gtk_actions.o : $(GTK_HEADERS)/gtk_actions.h
gtk_actions.o : $(HEADERS)/data_loading.h

debug : CFLAGS += -Wall -DDEBUG
debug : CC += cc

debug: $(OBJECTS)
	@echo "Łącze moduły *.o"
	$(CC) -o $@ $(GTK) $^

gra_w_zycie : CC += @cc
gra_w_zycie: $(OBJECTS)
	@echo "Łącze moduły *.o"
	@$(CC) -o $@ $(GTK) $^

main.o: ../main.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) $(HEADER_PATH) $(GTK) $^

mesh.o: $(LIB_DIR)/mesh.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

arg_handling.o: $(LIB_DIR)/arg_handling.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

error_handling.o: $(LIB_DIR)/error_handling.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

data_loading.o: $(LIB_DIR)/data_loading.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

cellular_automaton.o: $(LIB_DIR)/cellular_select_rules.c $(LIB_DIR)/cellular_formation_generation.c $(LIB_DIR)/cellular_automaton.c \
						$(HEADERS)/data_saving.h $(HEADERS)/image_generation.h $(HEADERS)/cellular_automaton.h
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

data_saving.o: $(LIB_DIR)/data_saving.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

image_generation.o: $(LIB_DIR)/image_generation.c	
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $^

graphics.o: $(LIB_DIR)/graphics.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) -I$(HEADERS) $(GTK) $^

gtk.o: $(GTK_SRC)/gtk.c $(GTK_SRC)/gtk_actions.c $(GTK_SRC)/gtk_menu.c 
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) $(HEADER_PATH) $(GTK) $^

graphic_interface.o: $(GTK_SRC)/graphic_interface.c
	@echo "Kompiluję moduł $@"
	$(CC) -c $(CFLAGS) $(HEADER_PATH) $(GTK) $^

.PHONY: clean

clean:
	rm *.o
	rm ../modules/headers/*.gch
	rm ../modules/gtk/headers/*.gch
