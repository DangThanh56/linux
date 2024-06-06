
LIB_NAME1 := thanh17
LIB_NAME2 := thanh2001

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static_lib
LIB_SHARED_DIR := $(LIB_DIR)/shared_lib
OBJ_DIR := $(CUR_DIR)/obj
SRC_DIR := $(CUR_DIR)/src

creat_obj_static_lib:
	gcc -c       $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(LIB_STATIC_DIR)
	gcc -c       $(SRC_DIR)/thanh.c -o $(OBJ_DIR)/thanh.o -I $(LIB_STATIC_DIR)
	gcc -c       $(SRC_DIR)/thanhthanh.c -o $(OBJ_DIR)/thanhthanh.o -I $(LIB_STATIC_DIR)

creat_static_lib:
	ar rcs $(LIB_STATIC_DIR)/lib$(LIB_NAME1).a $(OBJ_DIR)/thanh.o $(OBJ_DIR)/thanhthanh.o

linking_static_lib:
	gcc   $(OBJ_DIR)/main.o  -L$(LIB_STATIC_DIR) -l$(LIB_NAME1) -o $(BIN_DIR)/statically-linked

all_static_lib: creat_obj_static_lib creat_static_lib linking_static_lib

creat_obj_shared_lib:
	gcc -c       $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(LIB_STATIC_DIR)
	gcc -c       $(SRC_DIR)/thanh.c -o $(OBJ_DIR)/thanh.o -I $(LIB_STATIC_DIR)
	gcc -c       $(SRC_DIR)/thanhthanh.c -o $(OBJ_DIR)/thanhthanh.o -I $(LIB_STATIC_DIR)

creat_shared_lib:
	gcc -shared $(OBJ_DIR)/thanh.o $(OBJ_DIR)/thanhthanh.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME2).so

install: 
	cp -f $(LIB_SHARED_DIR)/lib$(LIB_NAME2).so /usr/lib

linking_shared_lib:
	gcc  $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -l$(LIB_NAME2) -o $(BIN_DIR)/use-shared-library

all_shared_lib: creat_obj_shared_lib creat_shared_lib install linking_shared_lib

clean: 
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_STATIC_DIR)/*.a
	rm -rf $(BIN_DIR)/*
