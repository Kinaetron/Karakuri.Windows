#pragma once
#include <vector>
#include "Bindable.h"
#include "VertexShader.h"
#include "LayoutDescriptor.h"

namespace Karakuri
{
	class InputLayout : public Bindable
	{
	public:
		InputLayout(Graphics& graphics, const std::vector<LayoutDescriptor>& layout, VertexShader& vertexShader);
		void Bind(Graphics& graphics) override;

	private:
		Microsoft::WRL::ComPtr< ID3D11InputLayout> inputLayout;
	};
}