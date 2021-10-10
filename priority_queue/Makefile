CC        := gcc

BIN       := .
OBJ       := .
INCLUDE   := .
SRC       := .
SRC_FILES := $(wildcard $(SRC)/*.c)
OBJ_FILES := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRC_FILES))

PROGRAM   := main

CFLAGS    := -I$(INCLUDE) -Wall -Wpedantic -std=c99
LEAKFLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(PROGRAM)

$(PROGRAM): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(PROGRAM)
	./$<

clean:
	rm -rf $(PROGRAM) $(OBJ_FILES)

zip:
	zip -r codes.zip Makefile *.c *.h

valgrind: CFLAGS += -g
valgrind: $(PROGRAM)
	valgrind $(LEAKFLAGS) $(PROGRAM)
