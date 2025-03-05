CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
CLIBS=-lraylib
BIN=./bin/boido
IN=main.c

build:
	@mkdir -p ./bin
	$(CC) -o $(BIN) $(IN) $(CFLAGS) $(CLIBS)

run:build
	$(BIN)
