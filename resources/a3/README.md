## How to use `removetest.c`.

I've included `maintest.c`, which includes a sample usage of operationstest. Essentially, all you need to do is pull in the
operationstest.h file into the target file (main.c for this assignment). I added a `test` to the Makefile, which can be run with `make test`. Next,
simply pass in a list to the `testRemove` function.  If the logic passes, the script will print `Operation validated.
Otherwise, it should print out a few ERROR messages. You can also pass in a `od` flag on the command line when running
the executable. That will enable a basic debug mode, which prints out a bunch of lines I used while fixing bugs.

Feel free to push changes to this code if you find any bugs. This was written VERY quickly.
