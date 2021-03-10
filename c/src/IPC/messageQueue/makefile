EXECUTABLE=myprogram
CC=gcc
CFLAGS=-Wall -O2
CPPFLAGS=
CXXFLAGS=$(CFLAGS)
COMPILE=$(CC) $(CPPFLAGS) $(CFLAGS) -c
SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))
DEPS:=$(patsubst %.c,%.d,$(SRCS))

all:$(EXECUTABLE)
$(EXECUTABLE):$(DEPS) $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS)

%.d: %.c
	$(CC) -M $(CPPFLAGS) $< > $@
	# $(CC) -M $(CPPFLAGS) $< | sed s/ \ \ .o/ .d >$@

%.o: %.c
	$(COMPILE) -o $@ $<

clean:
	-rm  $(OBJS) $(EXECUTABLE) $(DEPS) 

explain:
@echo "The following information represents your program:"
@echo "Final executable name :$(EXECUTABLE)"
@echo "Source files:$(SRCS)"
@echo "Object files:$(OBJS)"
@echo "Dependency files:$(DEPS)"

depend: $(DEPS)
	@echo "Depnendencies  are now up-to-date"
	-include $(DEPS)

