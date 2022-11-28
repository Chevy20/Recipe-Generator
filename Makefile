# Compiler being used (GNU)
CC = g++

# Compiler flags
CPP_FLAG = -std=c++1z -lsqlite3 -lwt -lwthttp -lcurl -L/opt/homebrew/lib -I/usr/local/include -v

all: test

test: test.o 
	$(CC) $(CPP_FLAG) test.o -o test 

test.o: test.cpp Model.cpp FoodItem.cpp StockTable.cpp SQLiteConnector.cpp FoodAPI.cpp Recipe.cpp Model.h FoodItem.h StockTable.h SQLiteConnector.h FoodAPI.hpp Recipe.h t_dbConnector.h t_dbTableStrategy.h
	$(CC)  -c test.cpp $(CPP_FLAG)
