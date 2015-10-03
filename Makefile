OBJS = map.o game.o character.o window.o
CXX = g++
OPT = -lncurses

main.out: $(OBJS)
	$(CXX) -Wall -O2 -o $@ $(OBJS) src/main.cpp $(OPT)

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
	$(CXX) -Wall -Wextra -pedantic -o test.out $(OBJS) test/test.cpp $(OPT)
	-./test.out

.PHONY: clean
clean:
	-rm *.o *.out

exec: main.out
	-./$<
	-rm *.o *.out

