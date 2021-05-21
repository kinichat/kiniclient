
CC=gcc
CFL=-Wall -Wextra -c
LFL=

CSRC=$(wildcard *.c)
COBJ=$(CSRC:%.c=build/%.o)

BIN=build/kini

.PHONY: all prebuild clean

all: prebuild $(BIN)

$(BIN): $(COBJ)
	@echo -e "LD\t$(BIN)"
	@$(CC) $(LFL) -o $(BIN) $(COBJ)

prebuild:
	@mkdir -p build

build/%.o: %.c
	@echo -e "CC\t$<"
	@$(CC) $(CFL) -o $@ $<

clean:
	@rm -rf build

