#include "Game.h"

namespace Karakuri
{
	Game::Game() 
	{
		this->Graphics = NULL;
	}
	Game::~Game() 
	{
		delete Graphics;
	}


	void Game::Loop()
	{
		timer.Update([&]() {
			Update();
		});

		Draw();
	}
	void Game::Initalize() { }

	void Game::Update() { }

	void Game::Draw() 
	{
		if (timer.GetFrameCount() == 0) {
			return;
		}
	}
}