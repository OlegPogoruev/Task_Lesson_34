#цель: зависимость
#[tab] команда


PROCCES_WAY = SoProces
PROCCES_NAME_1 = SoProces_1
PROCCES_NAME_2 = SoProces_2

BIN = Process_parent
SOURCES = main.c
HEADERS = main.h
CC := gcc

all:

	$(CC) $(PROCCES_WAY)/$(PROCCES_NAME_1).c -o $(PROCCES_WAY)/$(PROCCES_NAME_1).out
	$(CC) $(PROCCES_WAY)/$(PROCCES_NAME_2).c -o $(PROCCES_WAY)/$(PROCCES_NAME_2).out

	$(CC) $(SOURCES) -o $(BIN).out
$(BIN): $(HEADERS)

run: all
	./$(BIN).out

#clean:
#	rm -rf $(BIN) *.o $(BIN).out



















