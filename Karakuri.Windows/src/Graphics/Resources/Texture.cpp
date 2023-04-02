#include "Texture.h"
#include "../WICTextureLoader.h"

namespace Karakuri
{
	Texture::Texture(Graphics* graphics, const std::wstring& path)
	{
		auto reuslt = CreateWICTextureFromFile(
			GetDevice(graphics),
			GetContext(graphics),
			path.c_str(),
			NULL,
			textureShaderResourceView.GetAddressOf());
	}

	void Texture::Bind(Graphics* graphics) {
		GetContext(graphics)->PSSetShaderResources(0u, 1u, textureShaderResourceView.GetAddressOf());
	}
}