#pragma once
#include <string>
#include <memory>
#include "Timer.h"
#include "../Graphics/Graphics.h"

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

		void SetWidth(int width) { this->width = width; }
		void SetHeight(int height) { this->height = height; }
		void SetName(const std::wstring& name) { this->name = name; }
		void SetFrameRate(int frameRate) { this->timer.SetTargetFrameRate(frameRate); }

		const int GetWidth() const { return width; }
		const int GetHeight() const { return height; }
		const std::wstring& GetName() const { return name; }

	protected:
		Timer timer;
		int width = 1920;
		int height = 1080;
		std::wstring name = L"Karakuri Game";

	public:
		std::unique_ptr<Graphics> Graphics;

	};
	// To be defined in client
	Game* CreateGame();
}