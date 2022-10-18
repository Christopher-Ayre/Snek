CC = g++

HIDE_TERMINAL = -Wl,--subsystem,windows

CFLAGS = -O2 -Wall -Wno-missing-braces #$(HIDE_TERMINAL)
LFLAGS = -L lib/ -lraylib 
WINLFLAGS = -lopengl32 -lgdi32 -lwinmm
IFLAGS = -I include/

OBJ_FILES = main.o Snake.o Apple.o GameWorld.o
BUILD_DIR = build

EXE = Snek.exe

default: linux
	  
linux: $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	cp -r resources/ $(BUILD_DIR)/resources/
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(EXE) $(OBJ_FILES) $(IFLAGS) $(LFLAGS)

windows: $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	cp -r resources/ $(BUILD_DIR)/resources/
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(EXE) $(OBJ_FILES) $(IFLAGS) $(LFLAGS)	$(WINLFLAGS)

main.o: src/main.cpp src/Snake.h src/Apple.h
	$(CC) -c src/main.cpp $(CFLAGS) $(IFLAGS)

Snake.o: src/Snake.cpp src/Snake.h
	$(CC) -c src/Snake.cpp $(CFLAGS) $(IFLAGS)

Apple.o: src/Apple.cpp src/Apple.h
	$(CC) -c src/Apple.cpp $(CFLAGS) $(IFLAGS)

GameWorld.o: src/GameWorld.cpp src/GameWorld.h src/Apple.h src/Snake.h
	$(CC) -c src/GameWorld.cpp $(CFLAGS) $(IFLAGS)

clean: 
	rm -r $(BUILD_DIR)/*
	rm $(OBJ_FILES)