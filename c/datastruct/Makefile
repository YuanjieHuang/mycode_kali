src=$(wildcard *.c)
obj=$(patsubst %.c,%,$(src))
DIRS = Array  link  Graph \
    Graph/minestSpanningTree  Graph/search Graph/shortestDistance Graph/storage\
  InnerSort  LinerTable  LookupTbl  outerSort  Stack_Queue  String  Tree/binaryTree Tree/normalTree\ 
CC=gcc
RM= rm -f
CFLAGS= -lm -w
MAKE=make

all:
	for i in $(DIRS); do \
			(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
	done

.PHONY: all clean

clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done