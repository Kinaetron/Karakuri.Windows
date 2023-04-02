cbuffer ConstantBuffer {
    float4 color;
}

Texture2D textureIn;
SamplerState samplerIn;

float4 main(float2 textureCoordinate : TexCoord) : SV_TARGET {
    return mul(color, textureIn.Sample(samplerIn, textureCoordinate));
}