all: sort

sort: sort.h sort.c linkedlist.c main.c
	gcc main.c sort.c linkedlist.c -o sort

run: sort
	./sort

clean: 
	rm sort *.~