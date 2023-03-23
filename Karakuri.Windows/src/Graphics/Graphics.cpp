#include "Graphics.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "D3DCompiler.lib")

namespace Karakuri
{
	Graphics::Graphics(HWND hwnd, int width, int height)
	{
		DXGI_SWAP_CHAIN_DESC swapChainDescription = {};
		swapChainDescription.BufferDesc.Width = width;
		swapChainDescription.BufferDesc.Height = height;
		swapChainDescription.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swapChainDescription.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDescription.BufferDesc.RefreshRate.Denominator = 0;
		swapChainDescription.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapChainDescription.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapChainDescription.SampleDesc.Count = 1;
		swapChainDescription.SampleDesc.Quality = 0;
		swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDescription.BufferCount = 1;
		swapChainDescription.OutputWindow = hwnd;
		swapChainDescription.Windowed = TRUE;
		swapChainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDescription.Flags = 0;

		auto result = D3D11CreateDeviceAndSwapChain(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0u,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&swapChainDescription,
			&_swapChain,
			&_device,
			nullptr,
			&_deviceContext
		);

		Microsoft::WRL::ComPtr<ID3D11Resource> backBuffer;
		_swapChain->GetBuffer(0, __uuidof(ID3D11Resource), &backBuffer);
		_device->CreateRenderTargetView(backBuffer.Get(), NULL, &_renderTargetView);

		D3D11_VIEWPORT viewPort;
		viewPort.Width = static_cast<float>(width);
		viewPort.Height = static_cast<float>(height);
		viewPort.MinDepth = 0.0f;
		viewPort.MaxDepth = 1.0f;
		viewPort.TopLeftX = 0.0f;
		viewPort.TopLeftY = 0.0f;
		_deviceContext->RSSetViewports(1u, &viewPort);	
	}

	void Graphics::Clear(const Colour& colour) {
		_deviceContext->ClearRenderTargetView(_renderTargetView.Get(), colour.GetColour());	
	}

	void Karakuri::Graphics::Present() {
		_swapChain->Present(1u, 0u);
	}

	Graphics::~Graphics()
	{
	}
}