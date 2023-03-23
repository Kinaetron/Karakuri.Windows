#include "Core/Game.h"
#include "Core/EntryPoint.h"
#include "Graphics/Colours.h"

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
		Graphics->Clear(Karakuri::Colour::Black());
		Graphics->Present();
	}
};

Karakuri::Game* Karakuri::CreateGame() 
{
	auto game = new ExampleGame();

	game->SetWidth(1920);
	game->SetHeight(1080);
	game->SetName(L"Pluckers, gime that wet pepper extra wet extra crispy");
	game->SetFrameRate(60);

	return game;
}