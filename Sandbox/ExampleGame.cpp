#include "Core/Game.h"
#include "Core/EntryPoint.h"

class ExampleGame : public Karakuri::Game
{
public:
	ExampleGame() { }
	~ExampleGame() { }

	void Initalize() override
	{
	}

	void Update() override
	{
	}

	void Draw() override
	{
	}
};

Karakuri::Game* Karakuri::CreateGame() {
	return new ExampleGame();
}