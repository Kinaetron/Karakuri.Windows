#pragma once
#include "Bindable.h"

namespace Karakuri
{
	template<typename C>
	class ConstantBuffer : public Bindable
	{
	public:
		void Update(Graphics* graphics, const C& consts)
		{
			D3D11_MAPPED_SUBRESOURCE mappedSubResource;
			GetContext(graphics)->Map(
				constantBuffer.Get(), 
				0u, 
				D3D11_MAP_WRITE_DISCARD, 
				0u, 
				&mappedSubResource);

			memcpy(mappedSubResource.pData, &consts, sizeof(consts));
			GetContext(graphics)->Unmap(constantBuffer.Get(), 0u);

		}

		ConstantBuffer(Graphics* graphics, const C& consts)
		{
			D3D11_BUFFER_DESC constantBufferDescription;
			constantBufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			constantBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
			constantBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			constantBufferDescription.MiscFlags = 0u;
			constantBufferDescription.ByteWidth = sizeof(consts);
			constantBufferDescription.StructureByteStride = 0u;

			D3D11_SUBRESOURCE_DATA constantBufferSubresourceData = {};
			constantBufferSubresourceData.pSysMem = &consts;

			GetDevice(graphics)->CreateBuffer(
				&constantBufferDescription, 
				&constantBufferSubresourceData, 
				&constantBuffer);
		}

		ConstantBuffer(Graphics* graphics)
		{
			D3D11_BUFFER_DESC constantBufferDescription;
			constantBufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			constantBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
			constantBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			constantBufferDescription.MiscFlags = 0u;
			constantBufferDescription.ByteWidth = sizeof(C);
			constantBufferDescription.StructureByteStride = 0u;

			GetDevice(graphics)->CreateBuffer(
				&constantBufferDescription,
				NULL,
				&constantBuffer);
		}

	protected:
		Microsoft::WRL::ComPtr<ID3D11Buffer> constantBuffer;
	};

	template<typename C>
	class VertexConstantBuffer : public ConstantBuffer<C>
	{
		using ConstantBuffer<C>::constantBuffer;
		using Bindable::GetContext;
	public:
		using ConstantBuffer<C>::ConstantBuffer;
		void Bind(Graphics* graphics) override {
			GetContext(graphics)->VSSetConstantBuffers(0u, 1u, constantBuffer.GetAddressOf());
		}
	};

	template<typename C>
	class PixelConstantBuffer : public ConstantBuffer<C>
	{
		using ConstantBuffer<C>::constantBuffer;
		using Bindable::GetContext;
	public:
		using ConstantBuffer<C>::ConstantBuffer;
		void Bind(Graphics* graphics) override {
			GetContext(graphics)->PSSetConstantBuffers(0u, 1u, constantBuffer.GetAddressOf());
		}
	};
}