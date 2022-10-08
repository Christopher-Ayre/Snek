CC = g++

HIDE_TERMINAL = -Wl,--subsystem,windows

CFLAGS = -O2 -Wall -Wno-missing-braces #$(HIDE_TERMINAL)
LFLAGS = -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
IFLAGS = -I include/

OBJ_FILES = main.o Snake.o
BUILD_DIR = build

EXE = Snek.exe

default: $(EXE)
	  
$(EXE): $(OBJ_FILES)
	cp -r resources/ $(BUILD_DIR)/resources/
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(EXE) $(OBJ_FILES) $(IFLAGS) $(LFLAGS)

main.o: src/main.cpp
	$(CC) -c src/main.cpp $(CFLAGS) $(IFLAGS) $(LFLAGS)

Snake.o: src/Snake.cpp src/Snake.h
	$(CC) -c src/Snake.cpp $(CFLAGS) $(IFLAGS) $(LFLAGS)

clean: 
	rm -r $(BUILD_DIR)/*
	rm $(OBJ_FILES)