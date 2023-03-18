#include "Game.h"

namespace Karakuri
{
	Game::Game() { }
	Game::Game(int width, int height, const std::wstring& name)
	{
		_name = name;
		_width = width;
		_height = height;
	}
	Game::~Game() { }
	void Game::Initalize() { }
	void Game::Update() { }
	void Game::Draw() { }
}