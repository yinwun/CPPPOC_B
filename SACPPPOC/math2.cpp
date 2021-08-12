#include "math2.h"

#define	ASIN_DIV 64
#define	ATAN_DIV 64

double	atan_table[ATAN_DIV + 1] = {
	0.000000,  0.895174,  1.789911,  2.683775,
	3.576334,  4.467159,  5.355825,  6.241914,
	7.125016,  8.004729,  8.880659,  9.752425,
	10.619655, 11.481991, 12.339087, 13.190611,
	14.036243, 14.875682, 15.708638, 16.534838,
	17.354025, 18.165957, 18.970408, 19.767169,
	20.556045, 21.336859, 22.109448, 22.873665,
	23.629378, 24.376469, 25.114835, 25.844388,
	26.565051, 27.276763, 27.979474, 28.673147,
	29.357754, 30.033280, 30.699723, 31.357085,
	32.005383, 32.644640, 33.274888, 33.896167,
	34.508523, 35.112011, 35.706691, 36.292630,
	36.869898, 37.438572, 37.998732, 38.550465,
	39.093859, 39.629005, 40.156000, 40.674940,
	41.185925, 41.689059, 42.184443, 42.672185,
	43.152390, 43.625165, 44.090620, 44.548862,
	45.000000
};

float Atan(float x, float y)
{
	int		c = 0;
	float	a;
	float	r = 0;
	float	v, w;
	int		index1, index2;
	float	a1, a2;
	float	ratio;


	if (0.0 == x && 0.0 == y) {
		return 0.0;
	}

	if (x < 0) {
		c += 1;
		v = -x;
	}
	else {
		v = x;
	}

	if (y < 0) {
		c += 2;
		w = -y;
	}
	else {
		w = y;
	}

	if (v < w) {
		c += 4;
		index1 = (int)(v / w * ATAN_DIV);
		index2 = index1 + 1;
		ratio = (v / w * ATAN_DIV) - (float)index1;
	}
	else {
		index1 = (int)(w / v * ATAN_DIV);
		index2 = index1 + 1;
		ratio = (w / v * ATAN_DIV) - (float)index1;
	}

	if (index2 > ATAN_DIV) index2 = ATAN_DIV;
	a1 = (float)atan_table[index1];
	a2 = (float)atan_table[index2];
	a = (1 - ratio) * a1 + ratio * a2;

	switch (c) {
	case 0:
		r = a;
		break;
	case 1:
		r = 180.0f - a;
		break;
	case 2:
		r = 360.0f - a;
		break;
	case 3:
		r = 180.0f + a;
		break;
	case 4:
		r = 90.0f - a;
		break;
	case 5:
		r = 90.0f + a;
		break;
	case 6:
		r = 270.0f + a;
		break;
	case 7:
		r = 270.0f - a;
		break;
	}

	// StoneAge?
	r -= 135;
	if (r < 0.0) r += 360.0;
	/////////////

	return r;
}

void AdjustDir(float* dir)
{
	if (*dir >= 360.0) {
		*dir -= 360.0F;
		AdjustDir(dir);
	}
	else
		if (*dir < 0.0) {
			*dir += 360.0F;
			AdjustDir(dir);
		}
}