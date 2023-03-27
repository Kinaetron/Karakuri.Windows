#pragma once
#include "LayoutDescriptor.h"

namespace Karakuri
{
	class TextureCoordinateLayoutDescriptor : public LayoutDescriptor
	{
	public:
		TextureCoordinateLayoutDescriptor()
		{
			semanticName = "TexCoord";
			dxgiFormatType = DXGI_FORMAT_R32G32_FLOAT;
		}
	};
}