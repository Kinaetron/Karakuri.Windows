#include "VertexShader.h"

namespace Karakuri
{
	VertexShader::VertexShader(Graphics& graphics, const std::wstring& path)
	{
		D3DReadFileToBlob(path.c_str(), &bytecodeBlob);

		GetDevice(graphics)->CreateVertexShader(
			bytecodeBlob->GetBufferPointer(),
			bytecodeBlob->GetBufferSize(),
			nullptr,
			&vertexShader);
	}

	void VertexShader::Bind(Graphics& graphics) {
		GetContext(graphics)->VSSetShader(vertexShader.Get(), nullptr, 0u);
	}

	ID3DBlob* VertexShader::GetBytecode() const {
		return bytecodeBlob.Get();
	}

}