#include "PixelShader.h"

namespace Karakuri
{
	PixelShader::PixelShader(Graphics* graphics, const int size, const BYTE* shader)
	{
		GetDevice(graphics)->CreatePixelShader(shader, size, NULL, &pixelShader);
	}

	void PixelShader::Bind(Graphics* graphics) {
		GetContext(graphics)->PSSetShader(pixelShader.Get(), nullptr, 0u);
	}

	ID3DBlob* PixelShader::GetBytecode() const {
		return bytecodeBlob.Get();
	}
}