CC = gcc

SOURCES = \
	src/main.c \
	src/memory.c

main:
	$(CC) $(SOURCES) -o a.out -s


.PHONY: main
