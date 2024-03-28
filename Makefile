CC = g++ -g -Wall -Werror
LIBS = -lm
LIB = libgeometry.a
LIB_PATH = ./bin/
INCLUDE_PATH = ./include/
SRC_PATH = ./src/
SRC_LIB_PATH = ./src/libgeometry/
TARGET_PATH = ./bin/
TARGET = geometry
OBJ_PATH = ./obj/

SRC = $(wildcard $(SRC_PATH)*.cpp)
OBJ = $(patsubst $(SRC_PATH)%.cpp, $(OBJ_PATH)%.o, $(SRC))
SRC_LIB = $(wildcard $(SRC_LIB_PATH)*.cpp)
OBJ_LIB = $(patsubst $(SRC_LIB_PATH)%.cpp, $(OBJ_PATH)%.o, $(SRC_LIB))

all : $(TARGET)

$(TARGET) : check $(OBJ) $(LIB)
	$(CC) $(OBJ) -I$(INCLUDE_PATH) $(LIB_PATH)$(LIB) -o $(TARGET_PATH)$(TARGET) $(LIBS)

$(LIB) : $(OBJ_LIB)
	ar rcs $(LIB_PATH)$(LIB) $(OBJ_LIB)

clean :
	rm -rf bin/* obj/*

rebuild : clean $(TARGET)

$(OBJ_PATH)%.o : $(SRC_LIB_PATH)%.cpp
	$(CC) -I$(INCLUDE_PATH) -c $< -o $@
	
$(OBJ_PATH)%.o : $(SRC_PATH)%.cpp
	$(CC) -I$(INCLUDE_PATH) -c $< -o $@

check :
	if [ ! -d "$(OBJ_PATH)" ]; then mkdir $(OBJ_PATH); fi
	if [ ! -d "$(TARGET_PATH)" ]; then mkdir $(TARGET_PATH); fi
