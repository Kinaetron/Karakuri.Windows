#pragma once
#include "LayoutDescriptor.h"

namespace Karakuri
{
	static class TextureCoordinateLayoutDescriptor : public LayoutDescriptor
	{
		TextureCoordinateLayoutDescriptor()
		{
			semanticName = "TexCoord";
			dxgiFormatType = DXGI_FORMAT_R32G32_FLOAT;
		}
	};
}