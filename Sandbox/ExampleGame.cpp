#include "ExampleGame.h"
#include "Graphics/Colors.h"
#include "Core/EntryPoint.h"

using namespace Karakuri;
using namespace DirectX::SimpleMath;

void ExampleGame::Initalize()
{
	test1 = Texture(Graphics, L"test.jpg");
	test2 = Texture(Graphics, L"test2.jpg");
	test3 = Texture(Graphics, L"test3.jpg");
	renderer = SpriteRenderer(Graphics);
}

void ExampleGame::Update()
{
}

void ExampleGame::Draw()
{
	Graphics->Clear(Colors::Beige);

	renderer.Draw(test2, Vector2(1300.0f, 400.0f), DirectX::SimpleMath::Vector2(555.0f, 558.0f), Vector2::Zero, 0.0f, Colors::White);
	renderer.Draw(test3, Vector2(0.0f, 0.0f), DirectX::SimpleMath::Vector2(1080.0f, 778.0f), Vector2::Zero, 0.0f, Colors::White);
	renderer.Draw(test1, Vector2(100.0f, 100.0f), DirectX::SimpleMath::Vector2(828.0f, 809.0f), Vector2::Zero, 0.0f,Colors::White);

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