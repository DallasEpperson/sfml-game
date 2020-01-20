LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	@echo "** Building the game **"
	g++ -c "./entities/entity.cpp" -o "../build/entity.o"
	g++ -c "./states/state.cpp" -o "../build/state.o"
	g++ -c "./states/gamestate.cpp" -o "../build/gamestate.o"
	g++ -c "./states/mainmenustate.cpp" -o "../build/mainmenustate.o"
	g++ -c "button.cpp" -o "../build/button.o"
	g++ -c "game.cpp" -o "../build/game.o"
	g++ -c "main.cpp" -o "../build/main.o"
	g++ -o "../sfml-game" "../build/main.o" "../build/game.o" "../build/gamestate.o" "../build/mainmenustate.o" "../build/state.o" "../build/entity.o" "../build/button.o" $(LIBS)

clean:
	@echo "** Removing object files and executable **"
	$(RM) "../sfml-game" "../build/*.o"