#pragma once
#include "Core/Game.h"
#include "Graphics/SpriteRenderer/SpriteRenderer.h"

class ExampleGame : public Karakuri::Game
{
public:
	ExampleGame();
	~ExampleGame();
	void Initalize() override;
	void Update() override;
	void Draw() override;

private:
	Karakuri::SpriteRenderer renderer = NULL;
};