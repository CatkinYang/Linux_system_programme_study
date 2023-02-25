# $@ #^ #<
src = $(wildcard *.cpp)
target = $(patsubst %.cpp, %,$(src))
all:$(target)

%:%.cpp
	g++ $< -o $@

clean:
	-rm -rf $(target)

.PHONY: all clean
