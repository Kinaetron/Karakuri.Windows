cbuffer PixelConstantBufferSprite {
    float4 color;
}

Texture2D tex;
SamplerState splr;

float4 main(float2 tc : TexCoord) : SV_TARGET {
    return color * tex.Sample(splr, tc);
}