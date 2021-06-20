EXEC = imageStenography

SRC = $(wildcard BMP/*.c Decode/*.c Encode/*c IO/*c) main.c
HEADERS = -I$(wildcard BMP/*.h Dehode/*.h Enhode/*h IO/*h)
UNITY_DIR= -IUnity
TEST_FILES = test/*

CC = gcc
CFLAGS = -Wall -g -pthread # -Werror

.PHONY: all test clean 

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(HEADERS) -o $(EXEC)
clean:
	@rm -v $(EXEC) 
test: $(TEST_FILES)
	$(CC) $(TEST_FILES) $(UNITY_DIR) $(HEADERS) -g  -O0 -std=c99 -DTEST $(SRC) ./Unity/unity.c -o io_test\
		&& ./collumn_test
