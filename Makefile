TARGET = build/bin/sortview

CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -fsanitize=address
LDS    = -lraylib -lm

INC    = -I./include
SRC    = $(wildcard src/*.c)
OBJ    = $(patsubst src/%.c, build/cache/%.o, $(SRC))


.PHONY: all run

all: $(TARGET)

run: $(TARGET)
	./$< $(ARGS)


$(TARGET): $(OBJ)
	@mkdir -p build/bin
	$(CC) $(CFLAGS) -o $@ $^ $(LDS)

build/cache/%.o: src/%.c
	@mkdir -p build/cache
	$(CC) $(CFLAGS) -o $@ -c $^ $(INC)
