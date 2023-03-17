#include "Core/Game.h"
#include "Core/EntryPoint.h"

class ExampleGame : public Karakuri::Game
{
public:
	ExampleGame() { }
	~ExampleGame() { }
};

Karakuri::Game* Karakuri::CreateGame() {
	return new ExampleGame();
}