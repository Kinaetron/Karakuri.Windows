#include "Game.h"

namespace Karakuri
{
	Game::Game() { }
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