#pragma once

namespace Karakuri
{
	class Game
	{
	public:
		Game();
		virtual ~Game();
	};

	// To be defined in client
	Game* CreateGame();
}