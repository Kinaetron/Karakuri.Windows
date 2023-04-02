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
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		virtual ~Game();

		void Loop();
		virtual void Initalize();
		virtual void Update();
		virtual void Draw();

		void SetWidth(unsigned int width) { this->width = width; }
		void SetHeight(unsigned int height) { this->height = height; }
		void SetName(const std::wstring& name) { this->name = name; }
		void SetFrameRate(unsigned int frameRate) { this->timer.SetTargetFrameRate(frameRate); }

		const unsigned int GetWidth() const { return width; }
		const unsigned int GetHeight() const { return height; }
		const std::wstring& GetName() const { return name; }

	protected:
		Timer timer;
		unsigned int width = 1920;
		unsigned int height = 1080;
		std::wstring name = L"Karakuri Game";

	public:
		Graphics* Graphics;
	};
	// To be defined in client
	Game* CreateGame();
}