#include "Core/Game.h"
#include "Core/EntryPoint.h"
#include "Graphics/Colours.h"
#include "Graphics/Resources/IndexBuffer.h"
#include <memory>
#include <vector>
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
		Graphics->DrawTexturedQuadTest();
		Graphics->Present();
	}
};

Karakuri::Game* Karakuri::CreateGame() 
{
	 std::unique_ptr<ExampleGame> game =  std::make_unique<ExampleGame>();

	game->SetWidth(1920);
	game->SetHeight(1080);
	game->SetName(L"Pluckers, gimme that wet pepper extra wet extra crispy");
	game->SetFrameRate(60);

	return game.release();
}