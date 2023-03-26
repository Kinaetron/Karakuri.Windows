#pragma once
#include <vector>
#include "Bindable.h"

namespace Karakuri
{
	class IndexBuffer : public Bindable
	{
	public:
		IndexBuffer(Graphics& graphics, const std::vector<unsigned short>& indices);
		void Bind(Graphics& graphics) override;
		IndexBuffer(const IndexBuffer&) = delete;
		IndexBuffer& operator=(const IndexBuffer&) = delete;
		UINT GetCount() const;

	protected:
		UINT count;
		Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
	};
}