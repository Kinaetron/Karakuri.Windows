#pragma once
#include "Bindable.h"

namespace Karakuri
{
	class Sampler : public Bindable
	{
	public:
		Sampler(Graphics* graphics);
		void Bind(Graphics* graphics) override;

	private:
		Microsoft::WRL::ComPtr<ID3D11SamplerState> sampler;
	};
}