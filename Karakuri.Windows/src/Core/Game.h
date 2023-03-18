#pragma once
#include <string_view>

namespace Karakuri
{
	class Game
	{
	public:
		Game();
		Game(int width, int height, std::wstring_view name);
		virtual ~Game();
		virtual void Initalize();
		virtual void Update();
		virtual void Draw();

		int Width() { return _width; }
		int Height() { return _height; }
		std::wstring_view Name() { return _name; }

	private:
		int _width = 1920;
		int _height = 1080;
		std::wstring_view _name = L"Karakuri Game";
	};
	// To be defined in client
	Game* CreateGame();
}