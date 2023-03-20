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
		Game::~Game();
	}

	void Initalize() override
	{
		Game::Initalize();
	}

	void Update() override
	{
		Game::Update();
	}

	void Draw() override
	{
		Game::Draw();

		graphics->Clear();
		graphics->Present();
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