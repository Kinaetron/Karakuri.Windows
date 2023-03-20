#pragma once
#include "SystemIncludes.h"
#include "Game.h"
#include "../Graphics/Graphics.h"
#include <string>
#include <memory>

extern Karakuri::Game* Karakuri::CreateGame();

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	auto game = Karakuri::CreateGame();

	const wchar_t CLASS_NAME[] = L"Karakuri Engine";

	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		game->GetName().c_str(),
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		game->GetWidth(),
		game->GetHeight(),
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (hwnd == NULL)  {
		return 0;
	}

	game->Initalize();
	game->Graphics = std::make_unique<Karakuri::Graphics>(hwnd, game->GetWidth(), game->GetHeight());

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			game->Loop();
		}
	}

	return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}