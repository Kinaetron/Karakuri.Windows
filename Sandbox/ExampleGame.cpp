#include "Core/Game.h"
#include "Core/EntryPoint.h"
#include "Graphics/Colors.h"
#include "Graphics/Resources/VertexBuffer.h"
#include "Graphics/Resources/IndexBuffer.h"
#include "Graphics/Resources/Sampler.h"
#include "Graphics/Resources/Texture.h"
#include "Graphics/Resources/PixelShader.h"
#include "Graphics/Resources/VertexShader.h"
#include "Graphics/Resources/LayoutDescriptor.h"
#include "Graphics/Resources/InputLayout.h"
#include "Graphics/Resources/PositionLayoutDescriptor.h"
#include "Graphics/Resources/TextureCoordinateLayoutDescriptor.h"
#include <memory>
#include <vector>
#include <iostream>

class ExampleGame : public Karakuri::Game
{
public:
	ExampleGame() 
	{
	}

	~ExampleGame() 
	{
		Game::~Game();
	}

	void Initalize() override
	{
		Game::Initalize();
	}

	void Update() override
	{
		Game::Update();
	}

	void Draw() override
	{	
		struct Vertex
		{
			float x;
			float y;
			float u;
			float v;
		};

		Game::Draw();
		Graphics->Clear(Karakuri::Colors::Crimson);

		const std::vector<Vertex> vertices =
		{
			{  -0.5f,0.5f, 0.0f, 0.0f }, // top left
			{  0.5f, 0.5f, 1.0f, 0.0f }, // top right
			{  0.5f,-0.5f, 1.0f, 1.0f }, // bottom right
			{ -0.5f,-0.5f, 0.0f, 1.0f }, // bottom left
		};

		auto vertexBuffer = Karakuri::VertexBuffer(Graphics.get(), vertices);
		vertexBuffer.Bind(Graphics.get());

		const std::vector<unsigned short> indices = {
			0 , 1, 2, 0, 2, 3
		};

		auto indexBuffer = Karakuri::IndexBuffer(Graphics.get(), indices);
		indexBuffer.Bind(Graphics.get());

		auto sampler = Karakuri::Sampler(Graphics.get());
		sampler.Bind(Graphics.get());

		auto texture = Karakuri::Texture(Graphics.get(), L"test.jpg");
		texture.Bind(Graphics.get());

		auto pixelShader = Karakuri::PixelShader(Graphics.get(), L"PixelTextureShader.cso");
		pixelShader.Bind(Graphics.get());

		auto vertexShader = Karakuri::VertexShader(Graphics.get(), L"VertexTextureShader.cso");
		vertexShader.Bind(Graphics.get());

		auto positionLayout = Karakuri::PositionLayoutDescriptor();
		auto texCoordLayout = Karakuri::TextureCoordinateLayoutDescriptor();

		 const std::vector<Karakuri::LayoutDescriptor> layoutDescriptor = { positionLayout, texCoordLayout };

		auto layout = Karakuri::InputLayout(Graphics.get(), layoutDescriptor, vertexShader);
		layout.Bind(Graphics.get());

		Graphics->DrawIndex(6, 0u);
		Graphics->Present();
	}
};

Karakuri::Game* Karakuri::CreateGame() 
{
	 std::unique_ptr<ExampleGame> game =  std::make_unique<ExampleGame>();

	game->SetWidth(1920);
	game->SetHeight(1080);
	game->SetName(L"Pluckers, gimme that wet pepper extra wet extra crispy");
	game->SetFrameRate(60);

	return game.release();
}