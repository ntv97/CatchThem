CatchThem: CatchThem StateStack.cpp GameOverState.cpp State.cpp HomeState.cpp StateId.hpp WinState.cpp GameState.cpp -lsfml-graphics Item.cpp Corn.cpp Apple.cpp OnyxApple.cpp Orange.cpp Candy.cpp Bread.cpp Turkey.cpp Random.cpp Game.cpp
	g++ Main.cpp -o CatchThem StateStack.cpp GameOverState.cpp State.cpp HomeState.cpp StateId.hpp WinState.cpp GameState.cpp -lsfml-graphics Item.cpp Corn.cpp Apple.cpp OnyxApple.cpp Orange.cpp Candy.cpp Bread.cpp Turkey.cpp Boom.cpp Random.cpp Game.cpp -lsfml-window -lsfml-system -lpng -lsfml-audio

clean:
	rm -rf CatchThem
