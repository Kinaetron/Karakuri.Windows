#pragma once
#include <memory>
#include <algorithm>

namespace Karakuri 
{
	class Colour
	{
	public:
		Colour(float red, float green, float blue, float alpha)
		{
			colour[0] = red;
			colour[1] = green;
			colour[2] = blue;
			colour[3] = alpha;
		}
		~Colour() { }

		const float* GetColour() const { return colour; }

		const static std::unique_ptr<Colour> AliceBlue() { return std::make_unique<Colour>(0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> AntiqueWhite() { return std::make_unique<Colour>(0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f); }
		const static std::unique_ptr<Colour> Aqua() { return std::make_unique<Colour>(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Azure() { return std::make_unique<Colour>(0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Beige() { return std::make_unique<Colour>(0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f); }
		const static std::unique_ptr<Colour> Bisque() { return std::make_unique<Colour>(1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f); }
		const static std::unique_ptr<Colour> Black() { return std::make_unique<Colour>(0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> BlanchedAlmond() { return std::make_unique<Colour>(1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f); }
		const static std::unique_ptr<Colour> Blue() { return std::make_unique<Colour>(0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> BlueViolet() { return std::make_unique<Colour>(0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f); }
		const static std::unique_ptr<Colour> Brown() { return std::make_unique<Colour>(0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f); }
		const static std::unique_ptr<Colour> BurlyWood() { return std::make_unique<Colour>(0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f); }
		const static std::unique_ptr<Colour> CadetBlue() { return std::make_unique<Colour>(0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f); }
		const static std::unique_ptr<Colour> Chartreuse() { return std::make_unique<Colour>(0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Chocolate() { return std::make_unique<Colour>(0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f); }
		const static std::unique_ptr<Colour> Coral() { return std::make_unique<Colour>(1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f); }
		const static std::unique_ptr<Colour> CornflowerBlue() { return std::make_unique<Colour>(0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f); }
		const static std::unique_ptr<Colour> Cornsilk() { return std::make_unique<Colour>(1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f); }
		const static std::unique_ptr<Colour> Crimson() { return std::make_unique<Colour>(0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f); }
		const static std::unique_ptr<Colour> Cyan() { return std::make_unique<Colour>(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkBlue() { return std::make_unique<Colour>(0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkCyan() { return std::make_unique<Colour>(0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkGoldenrod() { return std::make_unique<Colour>(0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkGray() { return std::make_unique<Colour>(0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkGreen() { return std::make_unique<Colour>(0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkKhaki() { return std::make_unique<Colour>(0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkMagenta() { return std::make_unique<Colour>(0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkOliveGreen() { return std::make_unique<Colour>(0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkOrange() { return std::make_unique<Colour>(1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkOrchid() { return std::make_unique<Colour>(0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkRed() { return std::make_unique<Colour>(0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkSalmon() { return std::make_unique<Colour>(0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkSeaGreen() { return std::make_unique<Colour>(0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkSlateBlue() { return std::make_unique<Colour>(0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkSlateGray() { return std::make_unique<Colour>(0.184313729f, 0.309803933f, 0.309803933f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkTurquoise() { return std::make_unique<Colour>(0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f); }
		const static std::unique_ptr<Colour> DarkViolet() { return std::make_unique<Colour>(0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f); }
		const static std::unique_ptr<Colour> DeepPink() { return std::make_unique<Colour>(1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f); }
		const static std::unique_ptr<Colour> DeepSkyBlue() { return std::make_unique<Colour>(0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> DimGray() { return std::make_unique<Colour>(0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f); }
		const static std::unique_ptr<Colour> DodgerBlue() { return std::make_unique<Colour>(0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Firebrick() { return std::make_unique<Colour>(0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f); }
		const static std::unique_ptr<Colour> FloralWhite() { return std::make_unique<Colour>(1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f); }
		const static std::unique_ptr<Colour> ForestGreen() { return std::make_unique<Colour>(0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f); }
		const static std::unique_ptr<Colour> Fuchsia() { return std::make_unique<Colour>(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Gainsboro() { return std::make_unique<Colour>(0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f); }
		const static std::unique_ptr<Colour> GhostWhite() { return std::make_unique<Colour>(0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Gold() { return std::make_unique<Colour>(1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Goldenrod() { return std::make_unique<Colour>(0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f); }
		const static std::unique_ptr<Colour> Gray() { return std::make_unique<Colour>(0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f); }
		const static std::unique_ptr<Colour> Green() { return std::make_unique<Colour>(0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> GreenYellow() { return std::make_unique<Colour>(0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f); }
		const static std::unique_ptr<Colour> Honeydew() { return std::make_unique<Colour>(0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f); }
		const static std::unique_ptr<Colour> HotPink() { return std::make_unique<Colour>(1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f); }
		const static std::unique_ptr<Colour> IndianRed() { return std::make_unique<Colour>(0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f); }
		const static std::unique_ptr<Colour> Indigo() { return std::make_unique<Colour>(0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f); }
		const static std::unique_ptr<Colour> Ivory() { return std::make_unique<Colour>(1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f); }
		const static std::unique_ptr<Colour> Khaki() { return std::make_unique<Colour>(0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f); }
		const static std::unique_ptr<Colour> Lavender() { return std::make_unique<Colour>(0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f); }
		const static std::unique_ptr<Colour> LavenderBlush() { return std::make_unique<Colour>(1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f); }
		const static std::unique_ptr<Colour> LawnGreen() { return std::make_unique<Colour>(0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> LemonChiffon() { return std::make_unique<Colour>(1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightBlue() { return std::make_unique<Colour>(0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightCoral() { return std::make_unique<Colour>(0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightCyan() { return std::make_unique<Colour>(0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightGoldenrodYellow() { return std::make_unique<Colour>(0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightGreen() { return std::make_unique<Colour>(0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightGray() { return std::make_unique<Colour>(0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightPink() { return std::make_unique<Colour>(1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightSalmon() { return std::make_unique<Colour>(1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightSeaGreen() { return std::make_unique<Colour>(0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightSkyBlue() { return std::make_unique<Colour>(0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightSlateGray() { return std::make_unique<Colour>(0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightSteelBlue() { return std::make_unique<Colour>(0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f); }
		const static std::unique_ptr<Colour> LightYellow() { return std::make_unique<Colour>(1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f); }
		const static std::unique_ptr<Colour> Lime() { return std::make_unique<Colour>(0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> LimeGreen() { return std::make_unique<Colour>(0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f); }
		const static std::unique_ptr<Colour> Linen() { return std::make_unique<Colour>(0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f); }
		const static std::unique_ptr<Colour> Magenta() { return std::make_unique<Colour>(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Maroon() { return std::make_unique<Colour>(0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumAquamarine() { return std::make_unique<Colour>(0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumBlue() { return std::make_unique<Colour>(0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumOrchid() { return std::make_unique<Colour>(0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumPurple() { return std::make_unique<Colour>(0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumSeaGreen() { return std::make_unique<Colour>(0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumTurquoise() { return std::make_unique<Colour>(0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f); }
		const static std::unique_ptr<Colour> MediumVioletRed() { return std::make_unique<Colour>(0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f); }
		const static std::unique_ptr<Colour> MidnightBlue() { return std::make_unique<Colour>(0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f); }
		const static std::unique_ptr<Colour> MintCream() { return std::make_unique<Colour>(0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f); }
		const static std::unique_ptr<Colour> MistyRose() { return std::make_unique<Colour>(1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f); }
		const static std::unique_ptr<Colour> Moccasin() { return std::make_unique<Colour>(1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f); }
		const static std::unique_ptr<Colour> NavajoWhite() { return std::make_unique<Colour>(1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f); }
		const static std::unique_ptr<Colour> Navy() { return std::make_unique<Colour>(0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f); }
		const static std::unique_ptr<Colour> OldLace() { return std::make_unique<Colour>(0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f); }
		const static std::unique_ptr<Colour> Olive() { return std::make_unique<Colour>(0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> OliveDrab() { return std::make_unique<Colour>(0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f); }
		const static std::unique_ptr<Colour> Orange() { return std::make_unique<Colour>(1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> OrangeRed() { return std::make_unique<Colour>(1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> Orchid() { return std::make_unique<Colour>(0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f); }
		const static std::unique_ptr<Colour> PaleGoldenrod() { return std::make_unique<Colour>(0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f); }
		const static std::unique_ptr<Colour> PaleGreen() { return std::make_unique<Colour>(0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f); }
		const static std::unique_ptr<Colour> PaleTurquoise() { return std::make_unique<Colour>(0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f); }
		const static std::unique_ptr<Colour> PaleVioletRed() { return std::make_unique<Colour>(0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f); }
		const static std::unique_ptr<Colour> PapayaWhip() { return std::make_unique<Colour>(1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f); }
		const static std::unique_ptr<Colour> PeachPuff() { return std::make_unique<Colour>(1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f); }
		const static std::unique_ptr<Colour> Peru() { return std::make_unique<Colour>(0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f); }
		const static std::unique_ptr<Colour> Pink() { return std::make_unique<Colour>(1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f); }
		const static std::unique_ptr<Colour> Plum() { return std::make_unique<Colour>(0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f); }
		const static std::unique_ptr<Colour> PowderBlue() { return std::make_unique<Colour>(0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f); }
		const static std::unique_ptr<Colour> Purple() { return std::make_unique<Colour>(0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f); }
		const static std::unique_ptr<Colour> Red() { return std::make_unique<Colour>(1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> RosyBrown() { return std::make_unique<Colour>(0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f); }
		const static std::unique_ptr<Colour> RoyalBlue() { return std::make_unique<Colour>(0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f); }
		const static std::unique_ptr<Colour> SaddleBrown() { return std::make_unique<Colour>(0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f); }
		const static std::unique_ptr<Colour> Salmon() { return std::make_unique<Colour>(0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f); }
		const static std::unique_ptr<Colour> SandyBrown() { return std::make_unique<Colour>(0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f); }
		const static std::unique_ptr<Colour> SeaGreen() { return std::make_unique<Colour>(0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f); }
		const static std::unique_ptr<Colour> SeaShell() { return std::make_unique<Colour>(1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f); }
		const static std::unique_ptr<Colour> Sienna() { return std::make_unique<Colour>(0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f); }
		const static std::unique_ptr<Colour> Silver() { return std::make_unique<Colour>(0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f); }
		const static std::unique_ptr<Colour> SkyBlue() { return std::make_unique<Colour>(0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f); }
		const static std::unique_ptr<Colour> SlateBlue() { return std::make_unique<Colour>(0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f); }
		const static std::unique_ptr<Colour> SlateGray() { return std::make_unique<Colour>(0.439215720f, 0.501960814f, 0.564705908f, 1.000000000f); }
		const static std::unique_ptr<Colour> Snow() { return std::make_unique<Colour>(1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f); }
		const static std::unique_ptr<Colour> SpringGreen() { return std::make_unique<Colour>(0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f); }
		const static std::unique_ptr<Colour> SteelBlue() { return std::make_unique<Colour>(0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f); }
		const static std::unique_ptr<Colour> Tan() { return std::make_unique<Colour>(0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f); }
		const static std::unique_ptr<Colour> Teal() { return std::make_unique<Colour>(0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f); }
		const static std::unique_ptr<Colour> Thistle() { return std::make_unique<Colour>(0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f); }
		const static std::unique_ptr<Colour> Tomato() { return std::make_unique<Colour>(1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f); }
		const static std::unique_ptr<Colour> Transparent() { return std::make_unique<Colour>(0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f); }
		const static std::unique_ptr<Colour> Turquoise() { return std::make_unique<Colour>(0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f); }
		const static std::unique_ptr<Colour> Violet() { return std::make_unique<Colour>(0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f); }
		const static std::unique_ptr<Colour> Wheat() { return std::make_unique<Colour>(0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f); }
		const static std::unique_ptr<Colour> White() { return std::make_unique<Colour>(1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> WhiteSmoke() { return std::make_unique<Colour>(0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f); }
		const static std::unique_ptr<Colour> Yellow() { return std::make_unique<Colour>(1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f); }
		const static std::unique_ptr<Colour> YellowGreen() { return std::make_unique<Colour>(0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f); }

	private:
		float colour[4];
	};
}