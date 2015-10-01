OBJS = map.o game.o character.o
CXX = g++
OPT = -lncurses

game.out: $(OBJS)
	$(CXX) $(OPT) -Wall -O2 -o $@ $(OBJS)

character.o: src/character.cpp
	$(CXX) $(OPT) -c $<

game.o: src/game.cpp
	$(CXX) $(OPT) -c $<

map.o: src/map.cpp
	$(CXX) $(OPT) -c $<

.PHONY: clean
clean:
	-rm *.o *.out

exec: game.out
	./$<
	-rm *.o *.out

