c_src=$(wildcard *.c)
c_obj=$(patsubst %.c,%,$(c_src))
cpp_src=$(wildcard *.cpp)
cpp_obj=$(patsubst %.cpp,%,$(cpp_src))
# $(info $(c_obj))
CC=gcc
CXX=g++
RM= rm -f
CFLAGS= -lm  -lpthread
CXXFLAGS= -lm  -lpthread -std=c++11

all:$(c_obj) $(cpp_obj)
##将obj中所有无扩展名为的文件替换成扩展名为.c的文件
$(c_obj):%:%.c
	$(CC) $^ -o $@ $(CFLAGS) 
$(cpp_obj):%:%.cpp
	$(CC) $(CXXFLAGS) -o $@  

.PHONY: all clean

clean:
	$(RM) $(c_obj) $(cpp_obj)