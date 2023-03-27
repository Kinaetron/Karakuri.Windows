#pragma once
#include "LayoutDescriptor.h"

namespace Karakuri
{
	class PositionLayoutDescriptor : public LayoutDescriptor
	{
	public:
		PositionLayoutDescriptor()
		{
			semanticName = "Position";
			dxgiFormatType = DXGI_FORMAT_R32G32_FLOAT;
		}
	};
}
