all: doStuff

doStuff: main.c stuff.c Stuff.h
	gcc -g main.c stuff.c -o doStuff

run: doStuff
	./doStuff

valgrind: doStuff
	valgrind ./doStuff

checkStyle: main.c stuff.c Stuff.h
	clint.py main.c stuff.c Stuff.h

clean:
	rm -rf doStuff
