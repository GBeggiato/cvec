CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

BIN = cvec
MAIN = cvec.c

$(BIN): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(BIN)

clean:
	rm -f $(BIN)

expand:
	$(CC) -E $(MAIN) -o cvec.i
