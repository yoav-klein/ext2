
OBJS=a.o b.o c.o
DEPS=$(patsubst %.o, %.d, $(OBJS))
FLAGS=-ansi -Wall -Wextra -pedantic-errors -std=c++11
FOO=../../include/foo.h
CPP=g++

.PHONY: test
test:
	echo $(DEPS)

all:
	echo "all target"

-include $(DEPS) 


%.d: %.cpp 
	@echo "Generating .d file $@" 
	$(CPP) -MM $< > $@.$$$$
	

%.o: %.cpp
	@echo Compiling $<
