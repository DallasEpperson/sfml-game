LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	@echo "** Building the game **"
	g++ -c "main.cpp" -o "../build/main.o"
	g++ -o "../game" "../build/main.o" $(LIBS)

clean:
	@echo "** Removing object files and executable **"
	$(RM) "../game" "../build/*.o"