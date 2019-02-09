CC=g++
CFLAGS=-Wall -g -O0 -std=c++11
TARGET=smart-wc
TARGET_TEST=test-smart-wc
SRC=src/main.cpp src/WordCounter.cpp
SRC_TEST=src/WordCounter.cpp src/TestWordCounter.cpp
DEPS=-I headers/

default: main test 

main:
	$(CC) -o $(TARGET) $(SRC) $(DEPS) $(CFLAGS)

test:
	$(CC) -o $(TARGET_TEST) $(SRC_TEST) $(DEPS) $(CFLAGS)

clean:
	rm *wc 

run:		
	./$(TARGET_TEST)
	./$(TARGET)
