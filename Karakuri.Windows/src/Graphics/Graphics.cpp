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

	void Graphics::Clear(const Colour& colour) {
		deviceContext->ClearRenderTargetView(renderTargetView.Get(), colour.GetColour());	
	}

	void Karakuri::Graphics::Present() {
		swapChain->Present(1u, 0u);
	}

	void Graphics::DrawTriangleTest()
	{
		namespace wrl = Microsoft::WRL;
		HRESULT hr;

		struct Vertex
		{
			float x;
			float y;
		};

		const Vertex vertices[] =
		{
			{ 0.0f,0.5f },
			{ 0.5f,-0.5f },
			{ -0.5f,-0.5f },
		};

		wrl::ComPtr<ID3D11Buffer> vertexBuffer;

		D3D11_BUFFER_DESC bufferDescriptor = {};
		bufferDescriptor.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDescriptor.Usage = D3D11_USAGE_DEFAULT;
		bufferDescriptor.CPUAccessFlags = 0u;
		bufferDescriptor.MiscFlags = 0u;
		bufferDescriptor.ByteWidth = sizeof(vertices);
		bufferDescriptor.StructureByteStride = sizeof(Vertex);

		D3D11_SUBRESOURCE_DATA subResourceData = {};
		subResourceData.pSysMem = vertices;
		device->CreateBuffer(&bufferDescriptor, &subResourceData, &vertexBuffer);

		const UINT stride = sizeof(Vertex);
		const UINT offset = 0u;
		deviceContext->IASetVertexBuffers(0u, 1u, vertexBuffer.GetAddressOf(), &stride, &offset);

		wrl::ComPtr<ID3D11PixelShader> pixelShader;
		wrl::ComPtr<ID3DBlob> blob;
		D3DReadFileToBlob(L"PixelShader.cso", &blob);
		device->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &pixelShader);

		deviceContext->PSSetShader(pixelShader.Get(), NULL, 0u);

		wrl::ComPtr<ID3D11VertexShader> vertexShader;
		D3DReadFileToBlob(L"VertexShader.cso", &blob);
		device->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &vertexShader);

		deviceContext->VSSetShader(vertexShader.Get(), NULL, 0u);

		wrl::ComPtr<ID3D11InputLayout> inputLayout;

		const D3D11_INPUT_ELEMENT_DESC inputElementDescription[] =
		{
			{ "Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 }
		};

		device->CreateInputLayout(inputElementDescription,
			(UINT)std::size(inputElementDescription),
			blob->GetBufferPointer(),
			blob->GetBufferSize(),
			&inputLayout);

		deviceContext->IASetInputLayout(inputLayout.Get());

		deviceContext->OMSetRenderTargets(1u, renderTargetView.GetAddressOf(), NULL);

		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		deviceContext->Draw((UINT)std::size(vertices), 0u);
	}

	Graphics::~Graphics()
	{
	}
}