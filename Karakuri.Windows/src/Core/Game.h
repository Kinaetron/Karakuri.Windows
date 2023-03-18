#pragma once
#include <string>

namespace Karakuri
{
	class Game
	{
	public:
		Game();
		Game(int width, int height, const std::wstring &name);
		virtual ~Game();
		virtual void Initalize();
		virtual void Update();
		virtual void Draw();

		int Width() { return _width; }
		int Height() { return _height; }
		const std::wstring& Name() { return _name; }

	private:
		int _width = 1920;
		int _height = 1080;
		std::wstring _name = L"Karakuri Game";
	};
	// To be defined in client
	Game* CreateGame();
}