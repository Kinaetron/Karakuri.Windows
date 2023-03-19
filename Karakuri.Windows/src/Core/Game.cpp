#include "Game.h"

namespace Karakuri
{
	Game::Game() { }
	Game::~Game() { }


	void Game::Loop()
	{
		_timer.Update([&]() {
			Update();
		});

		Draw();
	}
	void Game::Initalize() { }

	void Game::Update() { }

	void Game::Draw() 
	{
		if (_timer.GetFrameCount() == 0) {
			return;
		}
	}
}