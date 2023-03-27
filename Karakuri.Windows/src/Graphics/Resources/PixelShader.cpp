#include "PixelShader.h"

namespace Karakuri
{
	PixelShader::PixelShader(Graphics* graphics, const std::wstring& path)
	{
		D3DReadFileToBlob(path.c_str(), &bytecodeBlob);

		GetDevice(graphics)->CreatePixelShader(
			bytecodeBlob->GetBufferPointer(),
			bytecodeBlob->GetBufferSize(),
			nullptr,
			&pixelShader);
	}

	void PixelShader::Bind(Graphics* graphics) {
		GetContext(graphics)->PSSetShader(pixelShader.Get(), nullptr, 0u);
	}

	ID3DBlob* PixelShader::GetBytecode() const {
		return bytecodeBlob.Get();
	}
}