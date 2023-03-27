#pragma once
#include "../Graphics.h"

namespace Karakuri
{
	class Bindable
	{
	public:
		virtual void Bind(Graphics* graphics) = 0;
		virtual ~Bindable() = default;

	protected:
		static ID3D11DeviceContext* GetContext(Graphics* graphics);
		static ID3D11Device* GetDevice(Graphics* graphics);
	};
}