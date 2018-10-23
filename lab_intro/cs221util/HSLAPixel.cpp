#include "HSLAPixel.h"

namespace cs221util {

	HSLAPixel::HSLAPixel(){
		h = 1.0;
		s = 0;
		l = 1.0;
		a = 1.0;
	}

	HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
		h = hue;
		s = saturation;
		l = luminance;
		a = 1.0;
	}

	HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha){
		h = hue;
		s = saturation;
		l = luminance;
		a = alpha;
	}
}