#pragma once
#include <cmath>
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

		Colour(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha)
		{
			colour[0] = static_cast<float>(std::max(maxColourValue, red)) / maxColourValue;
			colour[1] = static_cast<float>(std::max(maxColourValue, green)) / maxColourValue;
			colour[2] = static_cast<float>(std::max(maxColourValue, blue)) / maxColourValue;
			colour[3] = static_cast<float>(std::max(maxColourValue, alpha)) / maxColourValue;
		}

		~Colour() { }

		const float* GetColour() const { return colour; }

		const static Colour AliceBlue() { return Colour(0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f); }
		const static Colour AntiqueWhite() { return Colour(0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f); }
		const static Colour Aqua() { return Colour(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour Aquamarine() { return Colour(0.498039246f, 1.000000000f, 0.831372619f, 1.000000000f); }
		const static Colour Azure() { return Colour(0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour Beige() { return Colour(0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f); }
		const static Colour Bisque() { return Colour(1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f); }
		const static Colour Black() { return Colour(0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour BlanchedAlmond() { return Colour(1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f); }
		const static Colour Blue() { return Colour(0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour BlueViolet() { return Colour(0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f); }
		const static Colour Brown() { return Colour(0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f); }
		const static Colour BurlyWood() { return Colour(0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f); }
		const static Colour CadetBlue() { return Colour(0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f); }
		const static Colour Chartreuse() { return Colour(0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour Chocolate() { return Colour(0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f); }
		const static Colour Coral() { return Colour(1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f); }
		const static Colour CornflowerBlue() { return Colour(0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f); }
		const static Colour Cornsilk() { return Colour(1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f); }
		const static Colour Crimson() { return Colour(0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f); }
		const static Colour Cyan() { return Colour(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour DarkBlue() { return Colour(0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f); }
		const static Colour DarkCyan() { return Colour(0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f); }
		const static Colour DarkGoldenrod() { return Colour(0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f); }
		const static Colour DarkGray() { return Colour(0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f); }
		const static Colour DarkGreen() { return Colour(0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f); }
		const static Colour DarkKhaki() { return Colour(0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f); }
		const static Colour DarkMagenta() { return Colour(0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f); }
		const static Colour DarkOliveGreen() { return Colour(0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f); }
		const static Colour DarkOrange() { return Colour(1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f); }
		const static Colour DarkOrchid() { return Colour(0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f); }
		const static Colour DarkRed() { return Colour(0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour DarkSalmon() { return Colour(0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f); }
		const static Colour DarkSeaGreen() { return Colour(0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f); }
		const static Colour DarkSlateBlue() { return Colour(0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f); }
		const static Colour DarkSlateGray() { return Colour(0.184313729f, 0.309803933f, 0.309803933f, 1.000000000f); }
		const static Colour DarkTurquoise() { return Colour(0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f); }
		const static Colour DarkViolet() { return Colour(0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f); }
		const static Colour DeepPink() { return Colour(1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f); }
		const static Colour DeepSkyBlue() { return Colour(0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f); }
		const static Colour DimGray() { return Colour(0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f); }
		const static Colour DodgerBlue() { return Colour(0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f); }
		const static Colour Firebrick() { return Colour(0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f); }
		const static Colour FloralWhite() { return Colour(1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f); }
		const static Colour ForestGreen() { return Colour(0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f); }
		const static Colour Fuchsia() { return Colour(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour Gainsboro() { return Colour(0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f); }
		const static Colour GhostWhite() { return Colour(0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f); }
		const static Colour Gold() { return Colour(1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f); }
		const static Colour Goldenrod() { return Colour(0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f); }
		const static Colour Gray() { return Colour(0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f); }
		const static Colour Green() { return Colour(0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f); }
		const static Colour GreenYellow() { return Colour(0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f); }
		const static Colour Honeydew() { return Colour(0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f); }
		const static Colour HotPink() { return Colour(1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f); }
		const static Colour IndianRed() { return Colour(0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f); }
		const static Colour Indigo() { return Colour(0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f); }
		const static Colour Ivory() { return Colour(1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f); }
		const static Colour Khaki() { return Colour(0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f); }
		const static Colour Lavender() { return Colour(0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f); }
		const static Colour LavenderBlush() { return Colour(1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f); }
		const static Colour LawnGreen() { return Colour(0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f); }
		const static Colour LemonChiffon() { return Colour(1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f); }
		const static Colour LightBlue() { return Colour(0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f); }
		const static Colour LightCoral() { return Colour(0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f); }
		const static Colour LightCyan() { return Colour(0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour LightGoldenrodYellow() { return Colour(0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f); }
		const static Colour LightGreen() { return Colour(0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f); }
		const static Colour LightGray() { return Colour(0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f); }
		const static Colour LightPink() { return Colour(1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f); }
		const static Colour LightSalmon() { return Colour(1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f); }
		const static Colour LightSeaGreen() { return Colour(0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f); }
		const static Colour LightSkyBlue() { return Colour(0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f); }
		const static Colour LightSlateGray() { return Colour(0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f); }
		const static Colour LightSteelBlue() { return Colour(0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f); }
		const static Colour LightYellow() { return Colour(1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f); }
		const static Colour Lime() { return Colour(0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour LimeGreen() { return Colour(0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f); }
		const static Colour Linen() { return Colour(0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f); }
		const static Colour Magenta() { return Colour(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour Maroon() { return Colour(0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour MediumAquamarine() { return Colour(0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f); }
		const static Colour MediumBlue() { return Colour(0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f); }
		const static Colour MediumOrchid() { return Colour(0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f); }
		const static Colour MediumPurple() { return Colour(0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f); }
		const static Colour MediumSeaGreen() { return Colour(0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f); }
		const static Colour MediumSlateBlue() { return Colour(0.482352972f, 0.407843173f, 0.933333397f, 1.000000000f); }
		const static Colour MediumTurquoise() { return Colour(0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f); }
		const static Colour MediumVioletRed() { return Colour(0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f); }
		const static Colour MidnightBlue() { return Colour(0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f); }
		const static Colour MintCream() { return Colour(0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f); }
		const static Colour MistyRose() { return Colour(1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f); }
		const static Colour Moccasin() { return Colour(1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f); }
		const static Colour NavajoWhite() { return Colour(1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f); }
		const static Colour Navy() { return Colour(0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f); }
		const static Colour OldLace() { return Colour(0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f); }
		const static Colour Olive() { return Colour(0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f); }
		const static Colour OliveDrab() { return Colour(0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f); }
		const static Colour Orange() { return Colour(1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f); }
		const static Colour OrangeRed() { return Colour(1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f); }
		const static Colour Orchid() { return Colour(0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f); }
		const static Colour PaleGoldenrod() { return Colour(0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f); }
		const static Colour PaleGreen() { return Colour(0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f); }
		const static Colour PaleTurquoise() { return Colour(0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f); }
		const static Colour PaleVioletRed() { return Colour(0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f); }
		const static Colour PapayaWhip() { return Colour(1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f); }
		const static Colour PeachPuff() { return Colour(1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f); }
		const static Colour Peru() { return Colour(0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f); }
		const static Colour Pink() { return Colour(1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f); }
		const static Colour Plum() { return Colour(0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f); }
		const static Colour PowderBlue() { return Colour(0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f); }
		const static Colour Purple() { return Colour(0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f); }
		const static Colour Red() { return Colour(1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour RosyBrown() { return Colour(0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f); }
		const static Colour RoyalBlue() { return Colour(0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f); }
		const static Colour SaddleBrown() { return Colour(0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f); }
		const static Colour Salmon() { return Colour(0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f); }
		const static Colour SandyBrown() { return Colour(0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f); }
		const static Colour SeaGreen() { return Colour(0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f); }
		const static Colour SeaShell() { return Colour(1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f); }
		const static Colour Sienna() { return Colour(0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f); }
		const static Colour Silver() { return Colour(0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f); }
		const static Colour SkyBlue() { return Colour(0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f); }
		const static Colour SlateBlue() { return Colour(0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f); }
		const static Colour SlateGray() { return Colour(0.439215720f, 0.501960814f, 0.564705908f, 1.000000000f); }
		const static Colour Snow() { return Colour(1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f); }
		const static Colour SpringGreen() { return Colour(0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f); }
		const static Colour SteelBlue() { return Colour(0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f); }
		const static Colour Tan() { return Colour(0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f); }
		const static Colour Teal() { return Colour(0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f); }
		const static Colour Thistle() { return Colour(0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f); }
		const static Colour Tomato() { return Colour(1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f); }
		const static Colour Transparent() { return Colour(0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f); }
		const static Colour Turquoise() { return Colour(0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f); }
		const static Colour Violet() { return Colour(0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f); }
		const static Colour Wheat() { return Colour(0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f); }
		const static Colour White() { return Colour(1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f); }
		const static Colour WhiteSmoke() { return Colour(0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f); }
		const static Colour Yellow() { return Colour(1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f); }
		const static Colour YellowGreen() { return Colour(0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f); }

	private:
		float colour[4];
		const unsigned int maxColourValue = 255;
	};
}