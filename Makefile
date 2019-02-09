CC=g++
CFLAGS=-Wall -g -O0 -std=c++11
TARGET_NAME=test-smart-wc
SRC=src/*
DEPS=-I headers/

default: run 

test:
	$(CC) -o $(TARGET_NAME) $(SRC) $(DEPS) $(CFLAGS)

clean:
	rm test* 

run:	test	
	./$(TARGET_NAME)
