#pragma once
#include "LayoutDescriptor.h"

namespace Karakuri
{
	class PositionLayoutDescriptor : public LayoutDescriptor
	{
		PositionLayoutDescriptor()
		{
			semanticName = "Position";
			dxgiFormatType = DXGI_FORMAT_R32G32_FLOAT;
		}
	};
}
