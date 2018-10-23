#ifndef CPSC221_HSLAPIXEL_H
#define CPSC221_HSLAPIXEL_H

namespace cs221 util {
	class HSLAPIXEL{
		public:
			double h, s, l, a;

			/*

			You will create 3 constructors:

The default contstructor HSLAPixel() sets the default pixel to white, which is a pixel with any hue, saturation 0, luminance 1.0, and alpha 1.0.

A 3 argument constructor whose parameters are used to set the hue, saturation, and luminance.

A 4 argument constructor whose parameters are used to set the hue, saturation, luminance, and alpha.


			*/

			HSLAPixel ();
			HSLAPixel (double hue, double stauration, double luminance);
			HSLAPixel (double hue, double stauration, double luminance, double alpha);

	};
}

#endif