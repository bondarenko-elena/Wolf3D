#include "../includes/wolf3d.h"

unsigned int	add_smog(unsigned int c, double d)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = c;
	green = c >> 8;
	blue = c >> 16;
	d = 7 / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (red > 0)
		red = red - (red * d);
	if (green > 0)
		green = green - (green * d);
	if (blue > 0)
		blue = blue - (blue * d);
	return ((red << 16) + (green << 8) + blue);
}