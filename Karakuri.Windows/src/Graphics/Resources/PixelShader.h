#pragma once
#include <string>
#include "Bindable.h"

namespace Karakuri
{
	class PixelShader : public Bindable
	{
	public:
		PixelShader(Graphics& graphics, const std::wstring& path);
		void Bind(Graphics& graphics) override;
		ID3DBlob* GetBytecode() const;
	
	private:
		Microsoft::WRL::ComPtr<ID3DBlob> bytecodeBlob;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	};
}