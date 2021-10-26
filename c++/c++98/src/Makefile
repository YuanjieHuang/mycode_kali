src=$(wildcard *.cpp)
obj=$(patsubst %.cpp,%,$(src))

CC=gcc
CXX=g++
RM= rm -f
CFLAGS= -lm -w

all:$(obj)
##将obj中所有无扩展名为的文件替换成扩展名为.c的文件
$(obj):%:%.cpp
	$(CXX) $^ -o $@ $(CFLAGS) 

.PHONY: all clean

clean:
	$(RM) $(obj)