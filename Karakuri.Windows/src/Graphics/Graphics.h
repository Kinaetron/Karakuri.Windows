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
		 friend class Bindable;

	public:
		Graphics(HWND hwnd, unsigned int width, unsigned int height);
		Graphics(const Graphics&) = delete;
		Graphics& operator=(const Graphics&) = delete;
		~Graphics();

		const unsigned int Width() const { return width; }
		const unsigned int Height() const { return height; }

		void Clear(const Colour& colour);
		void Draw(unsigned int vertexCount, unsigned int vertexStart);
		void DrawIndex(unsigned int indexCount, unsigned int indexStart);
		void Present();
		void DrawTriangleTest();
		void DrawTexturedQuadTest();

	private:
		unsigned int width;
		unsigned int height;
		Microsoft::WRL::ComPtr<ID3D11Device> device;                                                                                                              
		Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;
	};
}             