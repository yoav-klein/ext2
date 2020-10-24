
OBJS=../a.o ../b.o ../c.o
DEPS=$(patsubst %.o, %.d, $(OBJS))
FLAGS=-ansi -Wall -Wextra -pedantic-errors -std=c++11
FOO=../../include/foo.h

.PHONY: test

all: $(OBJS)
	echo "all target"

-include $(DEPS) 


%.d: %.cpp 
	@echo "Generating .d file $@" 
	@echo $(patsubst %.d, %.o, $@): $(patsubst %.d, %.cpp, $@) > $@ \

%.o: %.cpp
	@echo Compiling $<
