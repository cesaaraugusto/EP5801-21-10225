#<Variables>
SRC := src
BUILD := build
BIN := build/bin

main.o: $(SRC)/main.c $(SRC)/calculador.c
	@if not exist "$(BIN)" mkdir "$(BIN)"
	@gcc -c $(SRC)/main.c -o $(BUILD)/main.o
	@gcc -c $(SRC)/calculador.c -o $(BUILD)/calculador.o
	@gcc $(BUILD)/main.o -o $(BIN)/main.exe
	@gcc $(BUILD)/calculador.o -o $(BIN)/calculador.exe