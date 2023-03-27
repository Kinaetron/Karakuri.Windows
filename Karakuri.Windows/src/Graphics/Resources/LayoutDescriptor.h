#pragma once
#include <string>
#include <dxgi.h>

namespace Karakuri
{
	class LayoutDescriptor
	{
		friend class InputLayout;

	public:
		LayoutDescriptor() { };
		virtual ~LayoutDescriptor() { };

	protected:
		std::string semanticName = {};
		DXGI_FORMAT dxgiFormatType = {};
	};
}