#include "Graphics.h"
#include "WICTextureLoader.h"

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

	void Graphics::Draw(unsigned int vertexCount, unsigned int vertexStart) {
		deviceContext->Draw(vertexCount, vertexStart);
	}

	void Graphics::DrawIndex(unsigned int indexCount, unsigned int indexStart) {
		deviceContext->DrawIndexed(indexCount, indexStart, 0u);
	}

	void Graphics::DrawTriangleTest()
	{
		namespace wrl = Microsoft::WRL;
		HRESULT hr = {};

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

	void Graphics::DrawTexturedQuadTest()
	{
		namespace wrl = Microsoft::WRL;
		HRESULT hr = {};

		struct Vertex
		{
			float x;
			float y;
			float u;
			float v;
		};

		const Vertex vertices[] =
		{
			{  -0.5f,0.5f, 0.0f, 0.0f }, // top left
			{  0.5f, 0.5f, 1.0f, 0.0f }, // top right
			{  0.5f,-0.5f, 1.0f, 1.0f }, // bottom right
			{ -0.5f,-0.5f, 0.0f, 1.0f }, // bottom left
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

		const unsigned short indices[] = {
			0 , 1, 2, 0, 2, 3
		};	

		wrl::ComPtr<ID3D11Buffer> indexBuffer;

		D3D11_BUFFER_DESC indexBufferDescriptor = {};
		indexBufferDescriptor.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDescriptor.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDescriptor.CPUAccessFlags = 0u;
		indexBufferDescriptor.MiscFlags = 0u;
		indexBufferDescriptor.ByteWidth = (6 * sizeof(unsigned int));
		indexBufferDescriptor.StructureByteStride = sizeof(unsigned short);

		subResourceData.pSysMem = indices;
		device->CreateBuffer(&indexBufferDescriptor, &subResourceData, &indexBuffer);

		deviceContext->IASetIndexBuffer(indexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);

		wrl::ComPtr<ID3D11SamplerState> sampler = {};

		D3D11_SAMPLER_DESC samplerDescriptor = {};
		samplerDescriptor.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerDescriptor.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerDescriptor.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerDescriptor.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

		device->CreateSamplerState(&samplerDescriptor, &sampler);

		deviceContext->PSSetSamplers(0, 1, sampler.GetAddressOf());

		wrl::ComPtr<ID3D11ShaderResourceView> textureShaderResourceView = {};

		auto result = CreateWICTextureFromFile(
			device.Get(), 
			deviceContext.Get(), 
			L"test.jpg", 
			NULL,
			textureShaderResourceView.GetAddressOf());

		deviceContext->PSSetShaderResources(0u, 1u, textureShaderResourceView.GetAddressOf());

		wrl::ComPtr<ID3D11PixelShader> pixelShader;
		wrl::ComPtr<ID3DBlob> blob;
		D3DReadFileToBlob(L"PixelTextureShader.cso", &blob);
		device->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &pixelShader);

		deviceContext->PSSetShader(pixelShader.Get(), NULL, 0u);

		wrl::ComPtr<ID3D11VertexShader> vertexShader;
		D3DReadFileToBlob(L"VertexTextureShader.cso", &blob);
		device->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &vertexShader);

		deviceContext->VSSetShader(vertexShader.Get(), NULL, 0u);

		wrl::ComPtr<ID3D11InputLayout> inputLayout;

		const D3D11_INPUT_ELEMENT_DESC inputElementDescription[] =
		{
			{ "Position",0,DXGI_FORMAT_R32G32_FLOAT,0,D3D11_APPEND_ALIGNED_ELEMENT,D3D11_INPUT_PER_VERTEX_DATA,0 },
			{ "TexCoord",0,DXGI_FORMAT_R32G32_FLOAT,0,D3D11_APPEND_ALIGNED_ELEMENT,D3D11_INPUT_PER_VERTEX_DATA,0 }
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

		deviceContext->DrawIndexed(6, 0u, 0u);
	}

	Graphics::~Graphics()
	{
	}
}