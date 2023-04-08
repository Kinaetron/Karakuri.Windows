#include "SpriteRenderer.h"
#include "../Resources/Texture.h"
#include "../Resources/Sampler.h"
#include "../Resources/IndexBuffer.h"
#include "../Resources/VertexBuffer.h"
#include "../Resources/PixelShader.h"
#include "../Resources/VertexShader.h"
#include "../Resources/InputLayout.h"
#include "../Resources/LayoutDescriptor.h"
#include "../Resources/PositionLayoutDescriptor.h"
#include "../Resources/TextureCoordinateLayoutDescriptor.h"



namespace Karakuri
{
	SpriteRenderer::SpriteRenderer(Graphics* const graphics)
	{
		if (graphics == NULL) {
			return;
		}

		projection = DirectX::SimpleMath::Matrix::CreateOrthographicOffCenter(0.0f, static_cast<float>(graphics->Width()), static_cast<float>(graphics->Height()), 0.0f, -1.0f, 1.0f);

		const std::vector<Vertex> vertices =
		{
			{  0.0f, 0.0f, 0.0f, 0.0f }, // top left
			{  1.0f, 0.0f, 1.0f, 0.0f }, // top right
			{  1.0f, 1.0f, 1.0f, 1.0f }, // bottom right
			{  0.0f, 1.0f, 0.0f, 1.0f }, // bottom left
		};

		auto vertexBuffer = Karakuri::VertexBuffer(graphics, vertices);
		vertexBuffer.Bind(graphics);

		const std::vector<unsigned short> indices = {
			0 , 1, 2, 0, 2, 3
		};

		auto indexBuffer = Karakuri::IndexBuffer(graphics, indices);
		indexBuffer.Bind(graphics);

		auto pixelShader = PixelShader(graphics, L"SpriteRendererPixelShader.cso");
		pixelShader.Bind(graphics);

		auto vertexShader = VertexShader(graphics, L"PixelRendererVertexShader.cso");
		vertexShader.Bind(graphics);

		auto sampler = Karakuri::Sampler(graphics);
		sampler.Bind(graphics);

		auto positionLayout = PositionLayoutDescriptor();
		auto texCoordLayout = TextureCoordinateLayoutDescriptor();

		const std::vector<LayoutDescriptor> layoutDescriptor = { positionLayout, texCoordLayout };

		auto layout = InputLayout(graphics, layoutDescriptor, vertexShader);
		layout.Bind(graphics);
	}

	void SpriteRenderer::Draw(Graphics* const graphics, Texture& texture, DirectX::SimpleMath::Vector2 position, DirectX::SimpleMath::Vector2 size, float rotate, DirectX::SimpleMath::Color color)
	{
		texture.Bind(graphics);

		auto model = DirectX::SimpleMath::Matrix::Identity;

		model = DirectX::SimpleMath::Matrix::CreateTranslation(DirectX::SimpleMath::Vector3(position.x, position.y, 0.0f)) * model;

		model = DirectX::SimpleMath::Matrix::CreateTranslation(DirectX::SimpleMath::Vector3(size.x * 0.5f, size.y * 0.5f, 0.0f)) * model;
		model = DirectX::SimpleMath::Matrix::CreateRotationZ(rotate) * model;
		model = DirectX::SimpleMath::Matrix::CreateTranslation(DirectX::SimpleMath::Vector3(size.x * -0.5f, size.y * -0.5f, 0.0f)) * model;

		model = DirectX::SimpleMath::Matrix::CreateScale(size.x, size.y, 1.0f) * model;

		auto vertexBufferConst = VertexConstantBufferSprite{ model, projection };
		auto vertexConstantBuffer = VertexConstantBuffer<VertexConstantBufferSprite>(graphics, vertexBufferConst);
		vertexConstantBuffer.Bind(graphics);

		auto pixelBufferConst = PixelConstantBufferSprite{ color };
		auto pixelConstantBuffer = PixelConstantBuffer<PixelConstantBufferSprite>(graphics, pixelBufferConst);
		pixelConstantBuffer.Bind(graphics);

		graphics->DrawIndex(6, 0u);
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}
}