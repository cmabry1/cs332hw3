FILE = HW3

build: $(FILE).c
	gcc -o HW3 HW3.c

.PHONY: db
db:
	gdb -tui $(FILE)

run:
	./$(FILE)
