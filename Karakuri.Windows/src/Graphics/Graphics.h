#pragma once
#include "../Core/SystemIncludes.h"
#include "Colours.h"
#include <wrl.h>
#include <d3d11.h>
#include <d3dcompiler.h>

namespace Karakuri
{
	 class Graphics
	{
	public:
		Graphics(HWND hwnd, int width, int height);
		~Graphics();
		void Clear(const Colour& colour);
		void Present();
		void DrawTriangleTest();

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> device;                                                                                                              
		Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;
	};
}             