#include "IndexBuffer.h"

namespace Karakuri
{
	IndexBuffer::IndexBuffer(Graphics* graphics, const std::vector<unsigned short>& indices) 
	{
		count = (UINT)indices.size();

		D3D11_BUFFER_DESC indexBufferDescriptor = {};
		indexBufferDescriptor.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDescriptor.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDescriptor.CPUAccessFlags = 0u;
		indexBufferDescriptor.MiscFlags = 0u;
		indexBufferDescriptor.ByteWidth = UINT(count * sizeof(unsigned short));
		indexBufferDescriptor.StructureByteStride = sizeof(unsigned short);

		D3D11_SUBRESOURCE_DATA indexSubresourceData = {};
		indexSubresourceData.pSysMem = indices.data();

		GetDevice(graphics)->CreateBuffer(&indexBufferDescriptor, &indexSubresourceData, &indexBuffer);
	}

	void IndexBuffer::Bind(Graphics* graphics) {
		GetContext(graphics)->IASetIndexBuffer(indexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);
	}

	UINT IndexBuffer::GetCount() const {
		return count;
	}
}