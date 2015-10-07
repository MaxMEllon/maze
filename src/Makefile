LDFLAGS = -ltinfo -lncurses
ifeq ($(CXX), clang++)
	CFLAGS = -Wall -Wextra -O2 -std=c++11 -stdlib=libc++
else
	CFLAGS = -Wall -Wextra -O2 -std=c++11
endif
TEST = -g -D"TEST"
LIBS =
INCLUDE = -I./include
OBJDIR  = ./obj
SOURCES = $(wildcard *.cpp)
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))


game: $(OBJECTS) $(LIBS)
	$(CXX) $(CFLAGS) $(INCLUDE) -o $@.out $^ main/main.cpp $(LDFLAGS)

test.out: $(OBJECTS) $(LIBS)
	$(CXX) $(CFLAGS) $(INCLUDE) $(TEST) -o obj/window.o -c window.cpp $(LDFLAGS)
	$(CXX) $(CFLAGS) $(INCLUDE) $(TEST) -o $@ $^ ../test/test.cpp $(LDFLAGS)
	-rm -rf obj/*.o

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(CXX) $(CFLAGS) $(INCLUDE) -o $@ -c $< $(LDFLAGS)

all: clean game.out

.PHONY: exec
exec: game
	-./game.out

.PHONY: test
test: test.out

clean:
	-rm -rf obj/*.o *.out
