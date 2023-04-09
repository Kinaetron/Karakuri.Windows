#include "VertexShader.h"

namespace Karakuri
{
	VertexShader::VertexShader(Graphics* graphics, const int size, const BYTE* shader)
	{
		D3DCreateBlob(size, &bytecodeBlob);
		memcpy(bytecodeBlob->GetBufferPointer(), shader, size);

		GetDevice(graphics)->CreateVertexShader(shader, size, NULL, &vertexShader);
	}

	void VertexShader::Bind(Graphics* graphics) {
		GetContext(graphics)->VSSetShader(vertexShader.Get(), nullptr, 0u);
	}

	ID3DBlob* VertexShader::GetBytecode() const {
		return bytecodeBlob.Get();
	}

}