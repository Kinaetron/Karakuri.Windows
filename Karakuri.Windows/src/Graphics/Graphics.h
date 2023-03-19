#pragma once
#include "../Core/SystemIncludes.h"
#include <wrl.h>
#include <d3d11.h>

namespace Karakuri
{
	class Graphics
	{
	public:
		Graphics(HWND hwnd, int width, int height);
		~Graphics();

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> _device;
		Microsoft::WRL::ComPtr<IDXGISwapChain> _swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _deviceContext;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView;
	};
}