#include "Graphics.h"
#include "WICTextureLoader.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "D3DCompiler.lib")

namespace Karakuri
{
	Graphics::Graphics(HWND hwnd, unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;

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
			&swapChain,
			&device,
			nullptr,
			&deviceContext
		);

		Microsoft::WRL::ComPtr<ID3D11Resource> backBuffer;
		swapChain->GetBuffer(0, __uuidof(ID3D11Resource), &backBuffer);
		device->CreateRenderTargetView(backBuffer.Get(), NULL, &renderTargetView);

		D3D11_VIEWPORT viewPort;
		viewPort.Width = static_cast<float>(width);
		viewPort.Height = static_cast<float>(height);
		viewPort.MinDepth = 0.0f;
		viewPort.MaxDepth = 1.0f;
		viewPort.TopLeftX = 0.0f;
		viewPort.TopLeftY = 0.0f;
		deviceContext->RSSetViewports(1u, &viewPort);	
	}

	void Graphics::Clear(const DirectX::SimpleMath::Color& colour) {
		deviceContext->ClearRenderTargetView(renderTargetView.Get(), colour);	
	}

	void Karakuri::Graphics::Present() 
	{
		auto something = swapChain->Present(1u, 0u);
	}

	void Graphics::Draw(unsigned int vertexCount, unsigned int vertexStart) 
	{
		deviceContext->OMSetRenderTargets(1u, renderTargetView.GetAddressOf(), NULL);
		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		deviceContext->Draw(vertexCount, vertexStart);
	}

	void Graphics::DrawIndex(unsigned int indexCount, unsigned int indexStart)
	{
		deviceContext->OMSetRenderTargets(1u, renderTargetView.GetAddressOf(), NULL);
		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		deviceContext->DrawIndexed(indexCount, indexStart, 0u);
	}

	Graphics::~Graphics()
	{
	}
}