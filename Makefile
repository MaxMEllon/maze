OBJS = map.o game.o character.o window.o
CXX = g++
OPT = -lncurses

main.out: $(OBJS)
	$(CXX) $(OPT) -Wall -O2 -o $@ $(OBJS) src/main.cpp

window.o: src/window.cpp
	$(CXX) $(OPT) -c $<

character.o: src/character.cpp
	$(CXX) $(OPT) -c $<

game.o: src/game.cpp
	$(CXX) $(OPT) -c $<

map.o: src/map.cpp
	$(CXX) $(OPT) -c $<

.PHONY: test
test: $(OBJS)
	$(CXX) $(OPT) -Wall -Wextra -pedantic -o test.out $(OBJS) test/test.cpp
	-./test.out

.PHONY: clean

clean:
	-rm *.o *.out

exec: game.out
	-./$<
	-rm *.o *.out

