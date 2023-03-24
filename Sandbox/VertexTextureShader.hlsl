struct VSOut
{
    float2 tex : TexCoord;
    float4 pos : SV_Position;
};


VSOut main(float2 pos : POSITION, float2 tex : TexCoord)
{
    VSOut vso;
    vso.pos = float4(pos.xy, 0.0f, 1.0f);
    vso.tex = tex;
    return vso;
}