CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
# Your .hpp files
DEPS = FibLFSR.hpp PhotoMagic.hpp
# Your compiled .o files
OBJECTS = FibLFSR.o  PhotoMagic.o 
# The name of your program
PROGRAM = PhotoMagic

.PHONY: all clean lint

all: $(PROGRAM) test $(PROGRAM).a

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test:  test.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(PROGRAM).a: $(OBJECTS)
	ar rcs $@ $^

clean:
	rm *.o $(PROGRAM) test $(PROGRAM).a

lint:
	cpplint *.cpp *.hpp