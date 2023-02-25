# $@ #^ #<
src = $(wildcard *.c)
target = $(patsubst %.c, %,$(src))
all:$(target)

%:%.c
	gcc $< -o $@ -Wall 

clean:
	-rm -rf $(target)

.PHONY: all clean
