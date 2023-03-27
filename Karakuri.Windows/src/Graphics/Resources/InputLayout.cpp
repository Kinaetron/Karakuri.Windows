#include "InputLayout.h"

namespace Karakuri
{
	InputLayout::InputLayout(Graphics* graphics, const std::vector<LayoutDescriptor>& layout, VertexShader& vertexShader)
	{
		std::vector<D3D11_INPUT_ELEMENT_DESC> internalLayout = {};

		for (size_t i = 0; i < layout.size(); i++) {
			internalLayout.push_back({ layout[i].semanticName.c_str(), 0, layout[i].dxgiFormatType, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0});
		}

		GetDevice(graphics)->CreateInputLayout(
			internalLayout.data(),
			(UINT)internalLayout.size(),
			vertexShader.GetBytecode()->GetBufferPointer(),
			vertexShader.GetBytecode()->GetBufferSize(),
			&inputLayout);
	}

	void InputLayout::Bind(Graphics* graphics) {
		GetContext(graphics)->IASetInputLayout(inputLayout.Get());
	}
}