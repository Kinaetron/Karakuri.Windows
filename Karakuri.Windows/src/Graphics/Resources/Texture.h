#pragma once
#include <string>
#include "Bindable.h"

namespace Karakuri
{
	class Texture : public Bindable
	{
	public:
		Texture() { };
		~Texture() { };
		Texture(Graphics* graphics, const std::wstring& path);
		void Bind(Graphics* graphics);

	protected:
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> textureShaderResourceView;
	};
}