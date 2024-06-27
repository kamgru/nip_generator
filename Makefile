main: main.c
	clang -Wall -Wextra -pedantic -lm main.c -o nipgen

clean:
	rm nipgen
