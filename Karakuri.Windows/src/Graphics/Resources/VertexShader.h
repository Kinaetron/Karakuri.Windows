#pragma once
#include <string>
#include "Bindable.h"

namespace Karakuri
{
	class VertexShader : public Bindable
	{
	public:
		VertexShader(Graphics& graphics, const std::wstring& path);
		void Bind(Graphics& graphics) override;
		ID3DBlob* GetBytecode() const;

	private:
		Microsoft::WRL::ComPtr<ID3DBlob> bytecodeBlob;
		Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	};
}