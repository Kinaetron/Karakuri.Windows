#include "ExampleGame.h"
#include "Graphics/Colors.h"
#include "Core/EntryPoint.h"


void ExampleGame::Initalize()
{
	test1 = Karakuri::Texture(Graphics, L"test.jpg");
	test2 = Karakuri::Texture(Graphics, L"test2.jpg");
	test3 = Karakuri::Texture(Graphics, L"test3.jpg");
	renderer = Karakuri::SpriteRenderer(Graphics);
}

void ExampleGame::Update()
{
}

void ExampleGame::Draw()
{
	Graphics->Clear(Karakuri::Colors::CornflowerBlue);

	//renderer.Draw(test1, DirectX::SimpleMath::Vector2(100.0f, 100.0f), DirectX::SimpleMath::Vector2(828.0f, 809.0f), 0.0f, Karakuri::Colors::White);
	//renderer.Draw(test2, DirectX::SimpleMath::Vector2(1300.0f, 400.0f), DirectX::SimpleMath::Vector2(555.0f, 558.0f), 0.0f, Karakuri::Colors::White);
	renderer.Draw(test3, DirectX::SimpleMath::Vector2(0.0f, 0.0f), DirectX::SimpleMath::Vector2(1080.0f, 778.0f), DirectX::SimpleMath::Vector2::Zero, 0.0f, Karakuri::Colors::White);

	Graphics->Present();
}

ExampleGame::~ExampleGame()
{
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