OBJS = map.o game.o character.o window.o
CXX = g++
OPT = -lncurses
TEST = -D"TEST"

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
	$(CXX) $(TEST) -c src/window.cpp $(OPT)
	$(CXX) -Wall -Wextra -pedantic -o test.out $(OBJS) test/test.cpp $(OPT)
	-rm *.o

.PHONY: clean
clean:
	-rm *.o *.out

exec: main.out
	-./$<
	-rm *.o *.out

