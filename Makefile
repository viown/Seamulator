CC = gcc

SOURCES = \
	src/main.c \
	src/memory.c \
	src/cpu.c \
	src/registers.c \
	src/load.c

main:
	$(CC) $(SOURCES) -o a.out -s


.PHONY: main
