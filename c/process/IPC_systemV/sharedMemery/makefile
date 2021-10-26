-include ../messageQueue/makefile
VPATH = ./:../messageQueue
export variable=value#该右值可以在后面定义
export variable=:value#禁止该右值在后面定义
export variable+=value#+=可以给变量追加值
export variable?=value
export#send all variable
override define command_zip
	@echo start making
	gcc reader.c -o reader
	gcc writer.c -o writer
endef

libs_for_gcc = -lgnu
	normal_libs =
	foo: $(objects)
	ifeq($(CC),gcc) #ifeq ifneq ifdef ifndef
		$(CC) -o foo $(objects) $(libs_for_gcc)
	else
		$(CC) -o foo $(objects) $(normal_libs)
	endif

writer: CFLAGS = -gcc
writer: writer.o
	# $(gcc) $(CFLAGS) writer.o
	gcc -g writer.o
writer.o: writer.c
	# $(gcc) $(CFLAGS) writer.c
	gcc -c writer.c


sources=foo.c bar.clean
	ifneq($(MAKECMDGOALS),clean)
	include $(sources:.c=.d)
endif


PHONY: all
all: 
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@


install:

print:

tar:


dist:


tags:


check:

test:


.PHONY: clean
clean:
	@-rm *.out