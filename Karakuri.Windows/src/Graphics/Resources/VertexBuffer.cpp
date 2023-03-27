#include "VertexBuffer.h"

namespace Karakuri
{
	void VertexBuffer::Bind(Graphics* graphics)
	{
		const UINT offset = 0u;
		GetContext(graphics)->IASetVertexBuffers(0u, 1u, vertexBuffer.GetAddressOf(), &stride, &offset);
	}
}