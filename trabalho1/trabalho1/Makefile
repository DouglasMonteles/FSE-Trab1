# Executavel
BINFOLDER := bin/
# .hpp
INCFOLDER := inc/
# .cpp
SRCFOLDER := src/
# .o
OBJFOLDER := obj/
CC := gcc
CFLAGS := -std=c99
LINKFLAGS := -lrt -lbcm2835
SRCFILES := $(wildcard src/*.c)
FILE=config_file.sh
CONFIG_FILE=`grep "^[^\#*/;]" $(FILE)`

all: $(SRCFILES:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/main $(LINKFLAGS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc $(LINKFLAGS)

run: bin/main
	bin/main

run-distr-server:
	bin/main distr $(CONFIG_FILE)

run-local-distr-server:
	bin/main distr 127.0.0.1 5000

run-central-server:
	bin/main central $(CONFIG_FILE)

run-local-central-server:
	bin/main central 127.0.0.1 5000

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
	touch obj/.gitkeep
	touch bin/.gitkeep