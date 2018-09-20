#include "../includes/wolf3d.h"

unsigned int	add_smog(unsigned int c, double distance)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = c;
	green = c >> 8;
	blue = c >> 16;
	distance = 7 / (100 / distance);
	if (distance > 0.9)
		distance = 0.9;
	if (red > 0)
		red = red - (red * distance);
	if (green > 0)
		green = green - (green * distance);
	if (blue > 0)
		blue = blue - (blue * distance);
	return ((red << 16) + (green << 8) + blue);
}