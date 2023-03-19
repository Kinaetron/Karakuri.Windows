#pragma once
#include <string>
#include "Timer.h"

namespace Karakuri
{
	class Game
	{
	public:
		Game();
		virtual ~Game();

		void Loop();
		virtual void Initalize();
		virtual void Update();
		virtual void Draw();

		void SetWidth(int width) { _width = width; }
		void SetHeight(int height) { _height = height; }
		void SetName(const std::wstring& name) { _name = name; }
		void SetFrameRate(int frameRate) { _timer.SetTargetFrameRate(frameRate); }

		int GetWidth() { return _width; }
		int GetHeight() { return _height; }
		const std::wstring& GetName() { return _name; }

	protected:
		Timer _timer;
		int _width = 1920;
		int _height = 1080;
		std::wstring _name = L"Karakuri Game";

	};
	// To be defined in client
	Game* CreateGame();
}