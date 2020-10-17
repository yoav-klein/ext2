SRC_DIR:=src
OBJ_DIR:=obj
INC_DIR:=include
DEP_DIR:=deps

SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

CPP=g++
FLAGS=-ansi -pedantic-errors -Wall -Wextra -g -std=c++11
FLAGS+=-I$(INC_DIR)
DEPS=$(patsubst $(SRC_DIR)/%.cpp, $(DEP_DIR)/%.d, $(SRCS))

.PHONY: test
test: test.out

test.out: test.cpp $(OBJS)
	$(CPP) $(FLAGS) $^ -o $@

-include $(DEPS)
	
# create dependecies files
$(DEP_DIR)/%.d: $(SRC_DIR)/*.cpp
	$(CPP) $(FLAGS) -MM -MT $(patsubst $(DEP_DIR)/%.d, $(OBJ_DIR)/%.o, $@) $< > $@ 
	
# compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(FLAGS) -c -o $@ $<
	
# create the directories if don't exist
$(OBJS): | $(OBJ_DIR)

$(DEPS) : | $(DEP_DIR)

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(DEP_DIR):
	mkdir $(DEP_DIR)


fs.out: file-systems.cpp
	echo $(CFLAGS)
	#$(CPP) $(FLAGS) $^ -I$(INCLUDE) -o $@


.PHONY: clean

clean:
	rm -rf *.out obj deps
