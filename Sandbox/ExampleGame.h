#pragma once
#include "Core/Game.h"
#include "Graphics/SpriteRenderer/SpriteRenderer.h"

class ExampleGame : public Karakuri::Game
{
public:
	ExampleGame() { };
	~ExampleGame();
	void Initalize() override;
	void Update() override;
	void Draw() override;

private:
	Karakuri::Texture test1;
	Karakuri::Texture test2;
	Karakuri::SpriteRenderer renderer = NULL;
};