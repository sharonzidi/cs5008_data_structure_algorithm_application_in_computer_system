all: tree

tree: tree.h search.c queue.h tree.c queue.c

	gcc -g tree.h search.c queue.h tree.c queue.c -o tree

run: tree
	./tree


clean: 
	rm -rf tree