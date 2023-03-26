#pragma once
#include <vector>
#include "Bindable.h"

namespace Karakuri
{
	class VertexBuffer : public Bindable
	{
	public:
		template<class V>
		VertexBuffer(Graphics& graphics, const std::vector<V> vertices)
		{
			D3D11_BUFFER_DESC bufferDescriptor = {};
			bufferDescriptor.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			bufferDescriptor.Usage = D3D11_USAGE_DEFAULT;
			bufferDescriptor.CPUAccessFlags = 0u;
			bufferDescriptor.MiscFlags = 0u;
			bufferDescriptor.ByteWidth = UINT(sizeof(V) * vertices.size());
			bufferDescriptor.StructureByteStride = sizeof(V);

			D3D11_SUBRESOURCE_DATA vertexSubresourceData = {};
			vertexSubresourceData.pSysMem = vertices.data();

			GetDevice(graphics)->CreateBuffer(&bufferDescriptor, &vertexSubresourceData, &vertexBuffer);
		}
		void Bind(Graphics& graphics) override;

	private:
		UINT stride;
		Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	};
}