#include "Bindable.h"

namespace Karakuri
{
	ID3D11DeviceContext* Bindable::GetContext(Graphics& graphics) {
		return graphics.deviceContext.Get();
	}

	ID3D11Device* Bindable::GetDevice(Graphics& graphics) {
		return graphics.device.Get();
	}
}