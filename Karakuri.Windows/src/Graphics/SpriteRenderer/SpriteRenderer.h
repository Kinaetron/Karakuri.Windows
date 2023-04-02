#pragma once
#include "../Colors.h"
#include "../Resources/Texture.h"
#include "../../Maths/SimpleMath.h"
#include "../Resources/ConstantBuffers.h"

namespace Karakuri
{
	struct VertexConstantBufferSprite
	{
		DirectX::SimpleMath::Matrix model;
		DirectX::SimpleMath::Matrix projection;
	};

	struct PixelConstantBufferSprite {
		DirectX::SimpleMath::Color color;
	};

	struct Vertex
	{
		float x;
		float y;
		float u;
		float v;
	};

	class SpriteRenderer
	{
	public:
		SpriteRenderer(Graphics* graphics);
		~SpriteRenderer();
		void Draw(
			Graphics* const graphics,
			Texture& texture,
			DirectX::SimpleMath::Vector2 position,
			DirectX::SimpleMath::Vector2 size = { 10, 10 },
			float rotate = 0.0f,
			DirectX::SimpleMath::Color color = Karakuri::Colors::White);

	private:
		DirectX::SimpleMath::Matrix projection;
	};
}