#include "ExampleGame.h"
#include "Graphics/Colors.h"
#include "Core/EntryPoint.h"

struct Vertex
{
	float x;
	float y;
	float u;
	float v;
};

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

	auto texture = Karakuri::Texture(Graphics, L"test.jpg");

	Graphics->Clear(Karakuri::Colors::CornflowerBlue);
	renderer.Draw(Graphics, texture, DirectX::SimpleMath::Vector2{ 500, 200 }, DirectX::SimpleMath::Vector2{ 100.0f, 100.0f }, 0.0f, Karakuri::Colors::White);
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