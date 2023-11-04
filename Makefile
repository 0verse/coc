CC=gcc
CFLAGS=-Wno-implicit-int
file=cocc
green=\033[0;32m
reset=\033[0m

.PHONY: all

all: $(file)

$(file): $(file).o
	@echo -e "${green}linking:${reset}"
	$(CC) $(CFLAGS) $(file).o -o $(file)

$(file).o: $(file).c
	@echo -e "${green}building:${reset}"
	$(CC) $(CFLAGS) -c $(file).c -o $(file).o

clean:
	@echo -e "${green}removing:${reset}"
	if [ -f ./$(file) ]; then \
		rm $(file) $(file).o; \
	fi
