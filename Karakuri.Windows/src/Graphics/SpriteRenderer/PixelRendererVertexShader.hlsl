cbuffer ConstantBuffer
{
    matrix model;
    matrix projection;
}

struct VertexShaderOut
{
    float2 textureCoordinate : TextureCoordinate;
    float4 position : SV_Position;
};


VertexShaderOut main(float2 position : Position, float2 textureCoordinate : TextureCoordinate)
{
    VertexShaderOut vertexShaderOut;
    vertexShaderOut.textureCoordinate = textureCoordinate;
    vertexShaderOut.position = mul(mul(projection, model), float4(position, 0.0f, 1.0f));
    
	return vertexShaderOut;
}