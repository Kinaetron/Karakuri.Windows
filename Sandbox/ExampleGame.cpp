#include "ExampleGame.h"
#include "Graphics/Colors.h"
#include "Core/EntryPoint.h"


ExampleGame::ExampleGame() { }

ExampleGame::~ExampleGame() { }

void ExampleGame::Initalize()
{
	renderer = Karakuri::SpriteRenderer(Graphics);
}

void ExampleGame::Update()
{
}

void ExampleGame::Draw()
{
	Graphics->Clear(Karakuri::Colors::Black);

	auto texture = Karakuri::Texture(Graphics, L"test.jpg");
	auto texture2 = Karakuri::Texture(Graphics, L"test2.jpg");

	renderer.Draw(Graphics, texture, DirectX::SimpleMath::Vector2(100.0f, 100.0f), DirectX::SimpleMath::Vector2(828.0f, 809.0f), 0.0f, Karakuri::Colors::White);
	renderer.Draw(Graphics, texture2, DirectX::SimpleMath::Vector2(1300.0f, 400.0f), DirectX::SimpleMath::Vector2(555.0f, 558.0f), 0.0f, Karakuri::Colors::White);

	Graphics->Present();
}


Karakuri::Game* Karakuri::CreateGame() 
{
	 std::unique_ptr<ExampleGame> game =  std::make_unique<ExampleGame>();

	game->SetWidth(1920);
	game->SetHeight(1080);
	game->SetName(L"Pluckers, gimme that wet pepper extra wet extra crispy");
	game->SetFrameRate(60);

	return game.release();
}