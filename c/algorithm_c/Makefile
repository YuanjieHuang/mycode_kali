DIRS = $(shell echo {01..10})
DIRS = 01 02 03 04 05 06 07 08 09 10 algorithm

all:
	for i in $(DIRS); do \
		(cd $$i && echo "making $$i" && $(MAKE) all) || exit 1; \
	done

clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done

help:
	@echo $(MAKE)
