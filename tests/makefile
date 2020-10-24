
SRC_DIR=../src
INCLUDE_DIR=../include
OBJ_DIR=../obj
DEP_DIR=../deps

MAIN=test
CLASSES:=$(shell cat classes.txt)
SRCS:=$(patsubst %, $(SRC_DIR)/%.cpp, $(CLASSES))
OBJS:=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS:=$(patsubst $(SRC_DIR)/%.cpp, $(DEP_DIR)/%.d, $(SRCS))
DEPS+=$(DEP_DIR)/$(MAIN).d

CPP=g++
FLAGS= -ansi -pedantic-errors -Wall -Wextra -g -std=c++11 -Wno-missing-field-initializers
FLAGS+=-I$(INCLUDE_DIR)

test.out:  $(OBJS) $(OBJ_DIR)/$(MAIN).o
	@echo $(OBJS)
	$(CPP) $(FLAGS) -o $@ $^

-include $(DEPS)

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cpp | $(DEP_DIR)
	@echo "Generating dep for $@"
	$(CPP) $(FLAGS) -MM -MT $(patsubst $(DEP_DIR)/%.d, $(OBJ_DIR)/%.o, $@) $< > $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CPP) $(FLAGS) -c -I$(INCLUDE_DIR) -o $@ $<



############## specific for test.cpp file

$(DEP_DIR)/$(MAIN).d: $(MAIN).cpp | $(DEP_DIR)
	$(CPP) $(FLAGS) -MM -MT $(OBJ_DIR)/$(MAIN).o $< > $@	 


$(OBJ_DIR)/$(MAIN).o: $(MAIN).cpp | $(OBJ_DIR)
	$(CPP) $(FLAGS) -c -o $@ $<


#############


$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(DEP_DIR):
	mkdir $(DEP_DIR)
	
	
.PHONY: clean

clean:
	rm *.out
	cd .. && make clean && cd tests
	
