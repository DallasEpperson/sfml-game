LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	@echo "** Building the game **"
	g++ -c "game.cpp" -o "../build/game.o"
	g++ -c "main.cpp" -o "../build/main.o"
	g++ -o "../sfml-game" "../build/main.o" "../build/game.o" $(LIBS)

clean:
	@echo "** Removing object files and executable **"
	$(RM) "../sfml-game" "../build/*.o"