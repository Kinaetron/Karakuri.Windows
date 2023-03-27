#include "Sampler.h"

namespace Karakuri
{
	Sampler::Sampler(Graphics* graphics)
	{
		D3D11_SAMPLER_DESC samplerDescriptor = {};
		samplerDescriptor.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerDescriptor.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerDescriptor.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerDescriptor.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

		GetDevice(graphics)->CreateSamplerState(&samplerDescriptor, &sampler);
	}

	void Sampler::Bind(Graphics* graphics) {
		GetContext(graphics)->PSSetSamplers(0, 1, sampler.GetAddressOf());
	}
}