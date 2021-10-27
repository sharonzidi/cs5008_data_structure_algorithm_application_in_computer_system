
output: start.c greeting.c goodbye.c
	gcc start.c greeting.c goodbye.c

start.c: start.c
	gcc -c start.c

greeting.c: greeting.c 
	gcc -c greeting.c

goodbye.c: goodbye.c
	gcc -c goodbye.c

clean: 
	rm *.c output