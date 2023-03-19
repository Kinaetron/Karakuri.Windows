#include "Core/Game.h"
#include "Core/EntryPoint.h"

#include <iostream>

class ExampleGame : public Karakuri::Game
{
public:
	ExampleGame() 
	{ 
	}

	~ExampleGame() 
	{ 
	}

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

Karakuri::Game* Karakuri::CreateGame() 
{
	auto game = new ExampleGame();

	game->SetWidth(1080);
	game->SetHeight(720);
	game->SetName(L"Example Game");
	game->SetFrameRate(120);

	return game;
}